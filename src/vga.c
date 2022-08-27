#include <stdarg.h>
#include <stdint.h>
#include <kstring.h>
#include <ports.h>
#include <vga.h>

int vga_rows;
int vga_cols;
int vga_x_pos;
int vga_y_pos;
unsigned char* vga_buffer; 

void vga_init(MULTIBOOT_INFO* mb_info) {
    vga_rows = mb_info->framebuffer_height;
    vga_cols = mb_info->framebuffer_width;
    vga_buffer = (unsigned char*)mb_info->framebuffer_addr;
    vga_disable_cursor();
}

void newline() {
    vga_x_pos = 0;
    vga_y_pos++;
    if (vga_y_pos >= vga_rows)
        vga_y_pos = 0;
    return;
}

void vga_debug() {
    printf("Row: %d, Col: %d\n", vga_y_pos, vga_x_pos);
}

void vga_disable_cursor() {
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
}

void putchar(char c) {
    if (c == '\n' || c == '\r') {
        newline();
        return;
    } else if (c == '\t') {
        for (int i = 0; i < 4; i++) 
            putchar(' ');
        return;
    } else {
        *(vga_buffer + (vga_x_pos + vga_y_pos * vga_cols) * 2) = c & 0xFF;
        *(vga_buffer + (vga_x_pos + vga_y_pos * vga_cols) * 2 + 1) = 7;

        vga_x_pos++;
        if (vga_x_pos >= vga_cols)
            newline();
    }

    return;
}

void printf(const char* _buf, ...) {
    va_list arg;
    va_start(arg, _buf);
    
    int format_int;
    char format_char;
    char* format_str;
    char bufprint[1024];
    
    for (int i = 0; i < strlen(_buf); i++) {
        char c = _buf[i];
        
        if (c == '%') {
            i++;
            c = _buf[i];
            
            switch (c) {
                case '%':
                    putchar('%');
                    break;
                case 'd': case 'i': case 'D': case 'I': case 'o': case 'O': case 'x': case 'X': case 'h': case 'H':
                    format_int = va_arg(arg, int); 
                    if (format_int < 0) {
                        putchar('-');
                        format_int *= -1;
                    }
                    
                    if (c == 'd' || c == 'i' || c == 'D' || c == 'I') // Decimal
                        itoa(format_int, bufprint, 10);
                    else if (c == 'o' || c == 'O') // Octals
                        itoa(format_int, bufprint, 8);
                    else if (c == 'x' || c == 'X' || c == 'h' || c == 'H') // Hexadecimal
                        itoa(format_int, bufprint, 16);
                    
                    for (int i = 0; bufprint[i] != '\0'; i++)
                        putchar(bufprint[i]);
                    break;
                case 'c': case 'C':
                    format_char = va_arg(arg, int);
                    putchar((char)format_char);
                    break;
                case 's': case 'S':
                    format_str = va_arg(arg, char*);
                    for (int i2 = 0; i2 < strlen(format_str); i2++) 
                        putchar(format_str[i2]);
                    break;
                default:
                    break;
            }
        }
        else 
            putchar(c);
    }
    va_end(arg);
}
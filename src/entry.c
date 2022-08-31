#include <multiboot.h>
#include <graphics.h>
#include <print.h>
#include <kstring.h>
#include <kmalloc.h>
#include <stdint.h>
#include <smbios.h>
#include <ports.h>
#include <power.h>
#include <utils.h>
#include <kmath.h>
#include <cmos.h>
#include <timer.h>
#include <shell.h>
#include <isr.h>
#include <gui.h>
#include <gdt.h>
#include <isr.h>

MULTIBOOT_INFO *mboot_info;

void ok_print(char* str) {
    printf("[");
    set_font_color(GREEN_COLOR);
    printf("OK");
    set_font_color(WHITE_COLOR);
    printf("] %s", str);
}

void err_print(char* str) {
    printf("[");
    set_font_color(RED_COLOR);
    printf("ERROR");
    set_font_color(WHITE_COLOR);
    printf("] %s", str);
}

void init_kernel() {
    init_graphics(mboot_info);
    ok_print("Initialized VESA successfully\n");
    ok_print("Multiboot info successfully stored\n");
    swap_buffers();

    ok_print("Booting with ");
    printf("%s\n", (char*)mboot_info->boot_loader_name);
    swap_buffers();

    gdt_init();
    ok_print("GDT initialized\n");
    swap_buffers();

    idt_init();
    ok_print("IDT initialized\n");
    ok_print("ISR initialized\n");
    swap_buffers();

    // init_memory_managment(mboot_info);
    // ok_print("Successfully initialized memory managment\n");
    // swap_buffers();

    keyboard_init();
    ok_print("Keyboard driver initialized\n");
    swap_buffers();

    Date date = get_date_cmos();
    ok_print("Successfully stored date by CMOS\n");
    ok_print("Actual date is ");
    printf("%d:%d:%d %d%d:%d:%d (UTC time zone)\n", date.hour, date.minut, date.second, date.century, date.year, date.month, date.day);
    swap_buffers();

    mouse_init();
    ok_print("Mouse driver initialized\n");
    swap_buffers();

    timer_init();
    ok_print("Timer initialized\n");
    swap_buffers();

    smbios_init();
    swap_buffers();

    ok_print("Starting to draw GUI\n");
    swap_buffers();

    return;
}

void kernel_entry(unsigned long magic, unsigned long addr) {
    if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
        return;

    mboot_info = (MULTIBOOT_INFO*)addr;
    init_kernel();
    loop_(addr);
    for (;;) {}
    return;
}

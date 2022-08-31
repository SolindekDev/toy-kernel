#include <graphics.h>
#include <utils.h>
#include <print.h>
#include <stdint.h>

void unimplemented(char* msg) {
    set_font_color(RED_COLOR);
    printf("unimplemented");
    set_font_color(WHITE_COLOR);
    printf(": %s", msg);
}

void* memcopy(void* dst, const void* src, int nbytes) {
    char* ret = dst;
    char* p = dst;
    const char* q = src;
    while (nbytes--)
        *p++ = *q++;
    return ret;
}

void memset(uint8_t *dest, uint8_t val, uint32_t len) {
    uint8_t *temp = (uint8_t *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

/*
    Glibc functions...
    most of it is taken from here: https://github.com/lattera/glibc
*/

// https://github.com/lattera/glibc/blob/master/sysdeps/wordsize-32/divdi3.c#L275
// long __divdi3(long u, long v) {
//     Wtype c = 0;
//     DWtype w;

//     if (u < 0) {
//         c = ~c;
//         u = -u;
//     }
//     if (v < 0) {
//         c = ~c;
//         v = -v;
//     }
//     w = __udivmoddi4(u, v, NULL);
//     if (c)
//         w = -w;
//     return w;
// }
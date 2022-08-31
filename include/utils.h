#pragma once

#include <stdint.h>

#define __BIG_ENDIAN

// https://github.com/lattera/glibc/blob/master/sysdeps/wordsize-32/divdi3.c#L27
typedef unsigned int UQItype	__attribute__ ((mode (QI)));
typedef          int SItype	__attribute__ ((mode (SI)));
typedef unsigned int USItype	__attribute__ ((mode (SI)));
typedef          int DItype	__attribute__ ((mode (DI)));
typedef unsigned int UDItype	__attribute__ ((mode (DI)));
#define Wtype SItype
#define HWtype SItype
#define DWtype DItype
#define UWtype USItype
#define UHWtype USItype
#define UDWtype UDItype
#define W_TYPE_SIZE 32

// https://github.com/lattera/glibc/blob/master/sysdeps/wordsize-32/divdi3.c#L49

#define ASSERT(cond) ((void)0)
#define NULL ((void*)0)
#define nullptr ((void*)0)

void  unimplemented(char* msg);
void* memcopy(void* dst, const void* src, int nbytes);
void  memset(uint8_t *dest, uint8_t val, uint32_t len);
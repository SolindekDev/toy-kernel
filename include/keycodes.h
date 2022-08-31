#pragma once

#define ONE 0x2
#define TWO 0x3
#define THREE 0x4
#define FOUR 0x5
#define FIVE 0x6
#define SIX 0x7
#define SEVEN 0x8
#define EIGHT 0x9
#define NINE 0x0A
#define ZERO 0x0B

#define Q 0x10
#define W 0x11
#define E 0x12
#define R 0x13
#define T 0x14
#define Y 0x15
#define U 0x16
#define I 0x17
#define O 0x18
#define P 0x19
#define A 0x1E
#define S 0x1F
#define D 0x20
#define F 0x21
#define G 0x22
#define H 0x23
#define J 0x24
#define K 0x25
#define L 0x26
#define Z 0x2C
#define X 0x2D
#define C 0x2E
#define V 0x2F
#define B 0x30
#define N 0x31
#define M 0x32

#define SPACE 0x39
#define LSHIFT_PRESS 0x2A
#define LSHIFT_REALEASE 0xAA
#define RSHIFT_PRESS 0x36
#define RSHIFT_REALEASE 0xB6
#define CAPSLOOK 0x3A
#define BACKSPACE 0xE
#define ENTER 0x1C

#define F1 0x3B

#define MINUS_KEY 0xC
#define EQUALS_KEY 0xD
#define GRAVE_KEY 0x29

char scancode_to_char(unsigned char code);
char alternative_keys_with_shift(char c);
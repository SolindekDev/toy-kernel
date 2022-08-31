#include <keycodes.h>

char scancode_to_char(unsigned char code) {
    switch (code) {
        case ONE:   return '1';
        case TWO:   return '2';
        case THREE: return '3';
        case FOUR:  return '4';
        case FIVE:  return '5';
        case SIX:   return '6';
        case SEVEN: return '7';
        case EIGHT: return '8';
        case NINE:  return '9';
        case ZERO:  return '0';
        case Q:     return 'q';
        case W:     return 'w';
        case E:     return 'e';
        case R:     return 'r';
        case T:     return 't';
        case Y:     return 'y';
        case U:     return 'u';
        case I:     return 'i';
        case O:     return 'o';
        case P:     return 'p';
        case A:     return 'a';
        case S:     return 's';
        case D:     return 'd';
        case F:     return 'f';
        case G:     return 'g';
        case H:     return 'h';
        case J:     return 'j';
        case K:     return 'k';
        case L:     return 'l';
        case Z:     return 'z';
        case X:     return 'x';
        case C:     return 'c';
        case V:     return 'v';
        case B:     return 'b';
        case N:     return 'n';
        case M:     return 'm';
        case SPACE: return ' ';
        default:    return '\0';
    }
}

char alternative_keys_with_shift(char c) {
    switch (c) {
        case '1': return '!';
        case '2': return '@';
        case '3': return '#';
        case '4': return '$';
        case '5': return '%';
        case '6': return '^';
        case '7': return '&';
        case '8': return '*';
        case '9': return '(';
        case '0': return ')';
    }

    return '\0';
}
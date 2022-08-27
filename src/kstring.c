#include <kstring.h>
#include <stdbool.h>

int strlen(const char* str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void reverse(char* str) {
    int c, i, j;
    for (i = 0, j = strlen(str)-1; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

void itoa(int num, char* str, int base) {
    int i = 0;
    bool is_neg = false;
    
    if (num == 0) { 
        str[i++] = '0';
        str[i] = '\0';
        return;
    } 
    if (num < 0 && base == 10) {
        is_neg = true;
        num = -num;
    }
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
    if (is_neg)
        str[i++] = '-';
    str[i] = '\0';
    reverse(str);
}
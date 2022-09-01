#include <kstring.h>
#include <stdbool.h>

int strlen(const char* str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char to_uppercase(char c) {
    return (char)c - 0x20;
}

char to_lowercase(char c) {
    return (char)c + 0x20;
}

void reverse(char* str) {
    int c, i, j;
    for (i = 0, j = strlen(str)-1; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

int strcmp(const char *s1, char *s2) {
    int i = 0;

    while ((s1[i] == s2[i])) {
        if (s2[i++] == 0)
            return 0;
    }
    return 1;
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

void pop_last_str(char* str) {
    int len = strlen(str);
    str[len-1] = '\0';
}

void append_str(char* str, char c) {
    int len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
}

// int n_tu(int number, int count) {
//     int result = 1;
//     while(count-- > 0)
//         result *= number;

//     return result;
// }

// void dtoa(float num, char* str) {
//     long long int length, length2, i, number, position, sign;
//     float number2;

//     sign = -1;
//     if (num< 0) {
//         sign = '-';
//         num *= -1;
//     }

//     number2 = num;
//     number = num;
//     length = 0;  
//     length2 = 0; 

//     while ((number2 - (float)number) != 0.0 && !((number2 - (float)number) < 0.0)) {
//         number2 = num * (n_tu(10.0, length2 + 1));
//         number = number2;

//         length2++;
//     }

//     for (length = (num> 1) ? 0 : 1; num> 1; length++)
//         num /= 10;

//     position = length;
//     length = length + 1 + length2;
//     number = number2;

//     if (sign == '-') {
//         length++;
//         position++;
//     }

//     for (i = length; i >= 0 ; i--) {
//         if (i == (length))
//             str[i] = '\0';
//         else if(i == (position))
//             str[i] = '.';
//         else if(sign == '-' && i == 0)
//             str[i] = '-';
//         else {
//             str[i] = (number % 10) + '0';
//             number /= 10;
//         }
//     }
// }
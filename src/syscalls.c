#include <syscalls.h>
#include <utils.h>
#include <isr.h>

const static SYSCALL_FUNC syscalls[SYSCALLS_LENGTH] = {
    nullptr, // 0
    sys_write, // sys_write
    nullptr, // 2
    nullptr, // 3
    nullptr, // 4
    nullptr, // 5
    nullptr, // 6
    nullptr, // 7
    nullptr, // 8
    nullptr, // 9
    nullptr, // 10
    nullptr, // 11
    nullptr, // 12
    nullptr, // 13
    nullptr, // 14
    nullptr, // 15
    nullptr, // 16
    nullptr, // 17
    nullptr, // 18
    nullptr, // 19
    nullptr, // 20
    nullptr, // 21
    nullptr, // 22
    nullptr, // 23
    nullptr, // 24
    nullptr, // 25
    nullptr, // 26
    nullptr, // 27
    nullptr, // 28
    nullptr, // 29
    nullptr, // 30
    nullptr, // 31
    nullptr, // 32
    nullptr, // 33
    nullptr, // 34
    nullptr, // 35
    nullptr, // 36
    nullptr, // 37
    nullptr, // 38
    nullptr, // 39
    nullptr, // 40
    nullptr, // 41
    nullptr, // 42
    nullptr, // 43
    nullptr, // 44
    nullptr, // 45
    nullptr, // 46
    nullptr, // 47
    nullptr, // 48
    nullptr, // 49
    nullptr, // 50
    nullptr, // 51
    nullptr, // 52
    nullptr, // 53
    nullptr, // 54
    nullptr, // 55
    nullptr, // 56
    nullptr, // 57
    nullptr, // 58
    nullptr, // 59
    nullptr, // 60
    nullptr, // 61
    nullptr, // 62
    nullptr, // 63
    nullptr, // 64
    nullptr, // 65
    nullptr, // 66
    nullptr, // 67
    nullptr, // 68
    nullptr, // 69
    nullptr, // 70
    nullptr, // 71
    nullptr, // 72
    nullptr, // 73
    nullptr, // 74
    nullptr, // 75
    nullptr, // 76
    nullptr, // 77
    nullptr, // 78
    nullptr, // 79
    nullptr, // 80
    nullptr, // 81
    nullptr, // 82
    nullptr, // 83
    nullptr, // 84
    nullptr, // 85
    nullptr, // 86
    nullptr, // 87
    nullptr, // 88
    nullptr, // 89
    nullptr, // 90
    nullptr, // 91
    nullptr, // 92
    nullptr, // 93
    nullptr, // 94
    nullptr, // 95
    nullptr, // 96
    nullptr, // 97
    nullptr, // 98
    nullptr, // 99
    nullptr, // 100
    nullptr, // 101
    nullptr, // 102
    nullptr, // 103
    nullptr, // 104
    nullptr, // 105
    nullptr, // 106
    nullptr, // 107
    nullptr, // 108
    nullptr, // 109
    nullptr, // 110
    nullptr, // 111
    nullptr, // 112
    nullptr, // 113
    nullptr, // 114
    nullptr, // 115
    nullptr, // 116
    nullptr, // 117
    nullptr, // 118
    nullptr, // 119
    nullptr, // 120
    nullptr, // 121
    nullptr, // 122
    nullptr, // 123
    nullptr, // 124
    nullptr, // 125
    nullptr, // 126
    nullptr, // 127
    nullptr, // 128
    nullptr, // 129
    nullptr, // 130
    nullptr, // 131
    nullptr, // 132
    nullptr, // 133
    nullptr, // 134
    nullptr, // 135
    nullptr, // 136
    nullptr, // 137
    nullptr, // 138
    nullptr, // 139
    nullptr, // 140
    nullptr, // 141
    nullptr, // 142
    nullptr, // 143
    nullptr, // 144
    nullptr, // 145
    nullptr, // 146
    nullptr, // 147
    nullptr, // 148
    nullptr, // 149
    nullptr, // 150
    nullptr, // 151
    nullptr, // 152
    nullptr, // 153
    nullptr, // 154
    nullptr, // 155
    nullptr, // 156
    nullptr, // 157
    nullptr, // 158
    nullptr, // 159
    nullptr, // 160
    nullptr, // 161
    nullptr, // 162
    nullptr, // 163
    nullptr, // 164
    nullptr, // 165
    nullptr, // 166
    nullptr, // 167
    nullptr, // 168
    nullptr, // 169
    nullptr, // 170
    nullptr, // 171
    nullptr, // 172
    nullptr, // 173
    nullptr, // 174
    nullptr, // 175
    nullptr, // 176
    nullptr, // 177
    nullptr, // 178
    nullptr, // 179
    nullptr, // 180
    nullptr, // 181
    nullptr, // 182
    nullptr, // 183
    nullptr, // 184
    nullptr, // 185
    nullptr, // 186
    nullptr, // 187
    nullptr, // 188
    nullptr, // 189
    nullptr, // 190
    nullptr, // 191
    nullptr, // 192
    nullptr, // 193
    nullptr, // 194
    nullptr, // 195
    nullptr, // 196
    nullptr, // 197
    nullptr, // 198
    nullptr, // 199
    nullptr, // 200
    nullptr, // 201
    nullptr, // 202
    nullptr, // 203
    nullptr, // 204
    nullptr, // 205
    nullptr, // 206
    nullptr, // 207
    nullptr, // 208
    nullptr, // 209
    nullptr, // 210
    nullptr, // 211
    nullptr, // 212
    nullptr, // 213
    nullptr, // 214
    nullptr, // 215
    nullptr, // 216
    nullptr, // 217
    nullptr, // 218
    nullptr, // 219
    nullptr, // 220
    nullptr, // 221
    nullptr, // 222
    nullptr, // 223
    nullptr, // 224
    nullptr, // 225
    nullptr, // 226
    nullptr, // 227
    nullptr, // 228
    nullptr, // 229
    nullptr, // 230
    nullptr, // 231
    nullptr, // 232
    nullptr, // 233
    nullptr, // 234
    nullptr, // 235
    nullptr, // 236
    nullptr, // 237
    nullptr, // 238
    nullptr, // 239
    nullptr, // 240
    nullptr, // 241
    nullptr, // 242
    nullptr, // 243
    nullptr, // 244
    nullptr, // 245
    nullptr, // 246
    nullptr, // 247
    nullptr, // 248
    nullptr, // 249
    nullptr, // 250
    nullptr, // 251
    nullptr, // 252
    nullptr, // 253
    nullptr, // 254
    nullptr, // 255
    nullptr, // 256
    nullptr, // 257
    nullptr, // 258
    nullptr, // 259
    nullptr, // 260
    nullptr, // 261
    nullptr, // 262
    nullptr, // 263
    nullptr, // 264
    nullptr, // 265
    nullptr, // 266
    nullptr, // 267
    nullptr, // 268
    nullptr, // 269
    nullptr, // 270
    nullptr, // 271
    nullptr, // 272
    nullptr, // 273
    nullptr, // 274
    nullptr, // 275
    nullptr, // 276
    nullptr, // 277
    nullptr, // 278
    nullptr, // 279
    nullptr, // 280
    nullptr, // 281
    nullptr, // 282
    nullptr, // 283
    nullptr, // 284
    nullptr, // 285
    nullptr, // 286
    nullptr, // 287
    nullptr, // 288
    nullptr, // 289
    nullptr, // 290
    nullptr, // 291
    nullptr, // 292
    nullptr, // 293
    nullptr, // 294
    nullptr, // 295
    nullptr, // 296
    nullptr, // 297
    nullptr, // 298
    nullptr, // 299
    nullptr, // 300
    nullptr, // 301
    nullptr, // 302
    nullptr, // 303
    nullptr, // 304
    nullptr, // 305
    nullptr, // 306
    nullptr, // 307
    nullptr, // 308
    nullptr, // 309
    nullptr, // 310
    nullptr, // 311
    nullptr, // 312
    nullptr, // 313
    nullptr, // 314
    nullptr, // 315
    nullptr, // 316
    nullptr, // 317
    nullptr, // 318
    nullptr, // 319
    nullptr, // 320
    nullptr, // 321
    nullptr, // 322
    nullptr, // 323
    nullptr, // 324
    nullptr, // 325
};

void syscall_handler(registers_t* regs) {
    SYSCALL_FUNC syscall = syscalls[regs->eax];

    if (syscall == nullptr) {
        printf("syscall is not found %d\n", regs->eax);
        swap_buffers();
        regs->eax = -1;
    }

    printf("calling syscall (0x80): 0x%x\n", regs->eax);
    swap_buffers();
    int syscall_return;
    syscall(
        &syscall_return,
        regs->eax,
        regs->ebx,
        regs->ecx,
        regs->edx,
        regs->esi,
        regs->edi,
        regs->ebp
    );
    asm volatile("ret" : : "a"(syscall_return));
    // TODO: set syscall_return to real eax register
}

void syscalls_init() {
    isr_register_interrupt_handler(SYSCALL_INTERRUPT_NUM, syscall_handler);
}

void sys_write(int* syscall_return, int eax, int ebx, int ecx, int edx, int esi, int edi, int ebp) {
    char* buf = (char*)ecx;
    int fd = ebx;
    int count = edx;

    for (int i = 0; i < count; i++)
        printf("%c", buf[i]);

    swap_buffers();
    *syscall_return = 1;
} 
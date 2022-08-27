; Set multiboot flags
MEMINFO     equ  1<<0
BOOTDEVICE  equ  1<<1
CMDLINE     equ  1<<2
MODULECOUNT equ  1<<3
SYMT        equ  48
MEMMAP      equ  1<<6
DRIVE       equ  1<<7
CONFIGT     equ  1<<8
BOOTLDNAME  equ  1<<9
APMT        equ  1<<10
VIDEO       equ  1<<11
VIDEO_FRAMEBUF equ  1<<12

; Magic header
FLAGS       equ  MEMINFO | BOOTDEVICE | CMDLINE | MODULECOUNT | SYMT | MEMMAP | DRIVE | CONFIGT | BOOTLDNAME | VIDEO_FRAMEBUF
MAGIC_HEADER       equ  0x1BADB002
CHECKSUM    equ -(MAGIC_HEADER + FLAGS)

; Bootloader magic number
BOOTLOADER_MAGIC  equ  0x2BADB002

; Section .multiboot
section .multiboot
    align 4
    dd MAGIC_HEADER
    dd FLAGS
    dd CHECKSUM

section .data
    align 4096

section .initial_stack, nobits
    align 4

stack_bottom:
    resb 104856
stack_top:

section .text
    global _start
    global MAGIC_HEADER
    global BOOTLOADER_MAGIC

_start:
    mov esp, stack_top ; Move stack pointer register to top of the stack
    extern kernel_entry ; Extern c function 
    mov eax, BOOTLOADER_MAGIC ; Set eax to bootloader magic (0x2BADB002)
    push ebx ; Second argument in entry.cpp (void kernel_entry) (unsigned long addr) have pointer to multiboot info structure
    push eax ; First argument in entry.cpp (void kernel_entry) (unsigned long magic) have BOOTLOADER MAGIC
    call kernel_entry ; Call c function from entry.cpp (void kernel_entry)
loop:
    jmp loop
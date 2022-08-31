# /usr/bin/sh
# Create dir bin/
mkdir -p bin/

# Compile kernel c++ files
clang -m32 -c src/entry.c -o bin/entry.o -ffreestanding -O3 -I./include/
clang -m32 -c src/8259_pic.c -o bin/8259_pic.o -ffreestanding -O3 -I./include/
clang -m32 -c src/gdt.c -o bin/gdt.o -ffreestanding -O3 -I./include/
clang -m32 -c src/graphics.c -o bin/graphics.o -ffreestanding -O3 -I./include/
clang -m32 -c src/idt.c -o bin/idt.o -ffreestanding -O3 -I./include/
clang -m32 -c src/isr.c -o bin/isr.o -ffreestanding -O3 -I./include/
clang -m32 -c src/kmath.c -o bin/kmath.o -ffreestanding -O3 -I./include/
clang -m32 -c src/kstring.c -o bin/kstring.o -ffreestanding -O3 -I./include/
clang -m32 -c src/ports.c -o bin/ports.o -ffreestanding -O3 -I./include/
clang -m32 -c src/print.c -o bin/print.o -ffreestanding -O3 -I./include/
clang -m32 -c src/keyboard.c -o bin/keyboard.o -ffreestanding -O3 -I./include/
clang -m32 -c src/utils.c -o bin/utils.o -ffreestanding -O3 -I./include/
clang -m32 -c src/keycodes.c -o bin/keycodes.o -ffreestanding -O3 -I./include/
clang -m32 -c src/cmos.c -o bin/cmos.o -ffreestanding -O3 -I./include/
clang -m32 -c src/mouse.c -o bin/mouse.o -ffreestanding -O3 -I./include/
clang -m32 -c src/timer.c -o bin/timer.o -ffreestanding -O3 -I./include/
clang -m32 -c src/smbios.c -o bin/smbios.o -ffreestanding -O3 -I./include/
clang -m32 -c src/power.c -o bin/power.o -ffreestanding -O3 -I./include/
clang -m32 -c src/gui.c -o bin/gui.o -ffreestanding -O3 -I./include/
clang -m32 -c src/shell.c -o bin/shell.o -ffreestanding -O3 -I./include/
clang -m32 -c src/kmalloc.c -o bin/kmalloc.o -ffreestanding -O3 -I./include/
clang -m32 -c src/syscalls.c -o bin/syscalls.o -ffreestanding -O3 -I./include/

# Compile assembler entry
nasm -felf32 ./asm/exception.asm -o ./asm/exception.o
nasm -felf32 ./asm/idt.asm -o ./asm/idt.o
nasm -felf32 ./asm/irq.asm -o ./asm/irq.o
nasm -felf32 ./asm/gdt.asm -o ./asm/gdt.o
nasm -felf32 ./asm/loader.asm -o ./asm/loader.o

# Link all files
ld -m elf_i386 -T linker.ld asm/exception.o   \
                            asm/irq.o         \
                            asm/gdt.o         \
                            asm/idt.o         \
                            asm/loader.o      \
                            bin/utils.o       \
                            bin/8259_pic.o    \
                            bin/kmath.o       \
                            bin/gdt.o         \
                            bin/graphics.o    \
                            bin/idt.o         \
                            bin/isr.o         \
                            bin/kstring.o     \
                            bin/ports.o       \
                            bin/keycodes.o    \
                            bin/keyboard.o    \
                            bin/cmos.o        \
                            bin/entry.o       \
                            bin/mouse.o       \
                            bin/smbios.o      \
                            bin/power.o       \
                            bin/timer.o       \
                            bin/shell.o       \
                            bin/gui.o         \
                            bin/kmalloc.o     \
                            bin/syscalls.o    \
                            bin/print.o -o bin/kernel.bin -nostdlib

# Is bin/kernel.bin a x86 multiboot binary
grub-file --is-x86-multiboot bin/kernel.bin

# Create dir isodir/boot/grub
mkdir -p isodir/boot/grub
# Copy bin/kernel.bin file to isodir/boot/kernel.bin
cp bin/kernel.bin isodir/boot/kernel.bin
# Copy grub.cfg file to isodir/boot/grub/grub.cfg
cp grub.cfg isodir/boot/grub/grub.cfg
# Create iso
grub-mkrescue -o ToyKernel.iso isodir

# Run iso
qemu-system-x86_64 -cdrom ToyKernel.iso -m 2G -monitor stdio -vga vmware

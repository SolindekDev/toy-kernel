# Create dir bin/
mkdir -p bin/

# Compile kernel c++ files
clang -m32 -c src/vga.c -o bin/vga.o -ffreestanding -O3 -Wall -Wextra -I./include/
clang -m32 -c src/kstring.c -o bin/kstring.o -ffreestanding -O3 -Wall -Wextra -I./include/
clang -m32 -c src/gdt.c -o bin/gdt.o -ffreestanding -O3 -Wall -Wextra -I./include/
clang -m32 -c src/ports.c -o bin/ports.o -ffreestanding -O3 -Wall -Wextra -I./include/
clang -m32 -c src/utils.c -o bin/utils.o -ffreestanding -O3 -Wall -Wextra -I./include/
clang -m32 -c src/isr.c -o bin/isr.o -ffreestanding -O3 -Wall -Wextra -I./include/
clang -m32 -c src/entry.c -o bin/entry.o -ffreestanding -O3 -Wall -Wextra -I./include/
clang -m32 -c src/bios32.c -o bin/bios32.o -ffreestanding -O3 -Wall -Wextra -I./include/

# Compile assembler entry
nasm -felf32 ./asm/loader.asm -o ./asm/loader.o
nasm -felf32 asm/load_gdt.asm -o asm/load_gdt.o
nasm -felf32 asm/idt.asm -o asm/idt.o
nasm -felf32 asm/bios32.asm -o asm/bios32.o

# Link all files
ld -m elf_i386 -T linker.ld bin/vga.o      \
                            bin/entry.o    \
                            bin/ports.o    \
                            bin/kstring.o  \
                            bin/isr.o      \
                            bin/gdt.o      \
                            bin/utils.o    \
                            bin/bios32.o   \
                            asm/load_gdt.o \
                            asm/idt.o      \
                            asm/bios32.o   \
                            asm/loader.o -o bin/kernel.bin -nostdlib

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
qemu-system-x86_64 -cdrom ToyKernel.iso

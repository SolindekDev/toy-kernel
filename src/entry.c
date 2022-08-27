#include <multiboot.h>
#include <vga.h>
#include <gdt.h>
#include <bios32.h>
#include <isr.h>

MULTIBOOT_INFO *mboot_info;

void print_multiboot_info(unsigned long magic, unsigned long addr) {
    printf("[OK] informations from multiboot:\n");
    printf("\tMultiboot magic number = 0x%x\n", magic);
    printf("\tMultiboot address structure = 0x%x\n", addr);
    printf("\tMultiboot flags = 0x%x\n", mboot_info->flags);
    printf("\tMemory low = %d KB\n", (unsigned)mboot_info->mem_low);
    printf("\tMemory high = %d KB\n", (unsigned)mboot_info->mem_high);
    printf("\tBoot device = 0x%x\n", (unsigned)mboot_info->boot_device);
    printf("\tFramebuffer addres = 0x%x\n", mboot_info->framebuffer_addr);
    printf("\tFramebuffer width = %d\n", mboot_info->framebuffer_width);
    printf("\tFramebuffer height = %d\n", mboot_info->framebuffer_height);
    printf("\tFramebuffer pitch = %d\n", mboot_info->framebuffer_pitch);
    printf("\tVBE control mode = 0x%x\n", mboot_info->vbe_control_info);
    printf("\tVBE mode info = 0x%x\n", mboot_info->vbe_mode_info);
    printf("\tVBE mode = 0x%x\n", mboot_info->vbe_mode);
}

void kernel_entry(unsigned long magic, unsigned long addr) {
    if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
        return;

    mboot_info = (MULTIBOOT_INFO*)addr;
    vga_init(mboot_info);
    printf("[OK] Initialized VGA successfully\n");
    printf("[OK] Multiboot info successfully stored\n");
    print_multiboot_info(magic, addr);
    init_descriptor_tables();
    printf("[OK] Global Description Tabel initialized\n");
    printf("[OK] Interrupt Description Tabel initialized\n");
    // asm volatile ("int $0x4");
    printf("[OK] BIOS32 initialized\n");
    bios32_init();

    registers16_t in = {0}, out = {0};
    in.ah = 0x0e;
    in.al = '!';
    bios32_service(0x10, &in, &out); 
    printf("AX: 0x%x, BX: 0x%x", out.ax, out.bx);

    for (;;) {}
    return;
}
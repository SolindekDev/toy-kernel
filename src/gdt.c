#include <stdint.h>
#include <graphics.h>
#include <print.h>
#include <gdt.h>
#include <utils.h>

GDT g_gdt[NO_GDT_DESCRIPTORS];
GDT_PTR g_gdt_ptr;

void gdt_set_entry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    GDT *this = &g_gdt[index];

    this->segment_limit = limit & 0xFFFF;
    this->base_low = base & 0xFFFF;
    this->base_middle = (base >> 16) & 0xFF;
    this->access = access;

    this->granularity = (limit >> 16) & 0x0F;
    this->granularity = this->granularity | (gran & 0xF0);

    this->base_high = (base >> 24 & 0xFF);
}

void gdt_init() {
    g_gdt_ptr.limit = sizeof(g_gdt) - 1;
    g_gdt_ptr.base_address = (uint32_t)g_gdt;

    gdt_set_entry(0, 0, 0, 0, 0);
    gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    gdt_set_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
    gdt_set_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

    load_gdt((uint32_t)&g_gdt_ptr);
}

// extern void gdt_flush(uint32_t);
// extern void idt_flush(uint32_t);

// extern void isr0();
// extern void isr1();
// extern void isr2();
// extern void isr3();
// extern void isr4();
// extern void isr5();
// extern void isr6();
// extern void isr7();
// extern void isr8();
// extern void isr9();
// extern void isr10();
// extern void isr11();
// extern void isr12();
// extern void isr13();
// extern void isr14();
// extern void isr15();
// extern void isr16();
// extern void isr17();
// extern void isr18();
// extern void isr19();
// extern void isr20();
// extern void isr21();
// extern void isr22();
// extern void isr23();
// extern void isr24();
// extern void isr25();
// extern void isr26();
// extern void isr27();
// extern void isr28();
// extern void isr29();
// extern void isr30();

// void init_idt();
// void idt_set_gate(unsigned char,uint32_t,uint16_t,unsigned char);
// void init_gdt();

// void memset_for_gdt(uint8_t *dest, uint8_t val, uint32_t len) {
//     uint8_t *temp = (uint8_t *)dest;
//     for ( ; len != 0; len--) *temp++ = val;
// }

// gdt_entry_t gdt_entries[5];
// gdt_ptr_t   gdt_ptr;
// idt_entry_t idt_entries[256];
// idt_ptr_t   idt_ptr; 

// void init_descriptor_tables() {
//     init_gdt();
//     init_idt();
// }

// void init_gdt() {
//     gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
//     gdt_ptr.base  = (uint32_t)&gdt_entries;

//     gdt_set_gate(0, 0, 0, 0, 0);                
//     gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); 
//     gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); 
//     gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
//     gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); 

//     gdt_flush((uint32_t)&gdt_ptr);
// }

// void gdt_set_gate(int num, uint32_t base, uint32_t limit, char access, char gran) {
//     gdt_entries[num].base_low    = (base & 0xFFFF);
//     gdt_entries[num].base_middle = (base >> 16) & 0xFF;
//     gdt_entries[num].base_high   = (base >> 24) & 0xFF;

//     gdt_entries[num].limit_low   = (limit & 0xFFFF);
//     gdt_entries[num].granularity = (limit >> 16) & 0x0F;

//     gdt_entries[num].granularity |= gran & 0xF0;
//     gdt_entries[num].access      = access;
// } 

// void init_idt() {
//     idt_ptr.limit = sizeof(idt_entry_t) * 256 -1;
//     idt_ptr.base  = (uint32_t)&idt_entries;

//     memset_for_gdt((uint8_t*)&idt_entries, 0, sizeof(idt_entry_t)*256);

//     idt_set_gate(0, (uint32_t)isr0, 0x08, 0x8E);
//     idt_set_gate(1, (uint32_t)isr1, 0x08, 0x8E);
//     idt_set_gate(2, (uint32_t)isr2, 0x08, 0x8E);
//     idt_set_gate(3, (uint32_t)isr3, 0x08, 0x8E);
//     idt_set_gate(4, (uint32_t)isr4, 0x08, 0x8E);
//     idt_set_gate(5, (uint32_t)isr5, 0x08, 0x8E);
//     idt_set_gate(6, (uint32_t)isr6, 0x08, 0x8E);
//     idt_set_gate(7, (uint32_t)isr7, 0x08, 0x8E);
//     idt_set_gate(8, (uint32_t)isr8, 0x08, 0x8E);
//     idt_set_gate(9, (uint32_t)isr9, 0x08, 0x8E);
//     idt_set_gate(10, (uint32_t)isr10, 0x08, 0x8E);
//     idt_set_gate(11, (uint32_t)isr11, 0x08, 0x8E);
//     idt_set_gate(12, (uint32_t)isr12, 0x08, 0x8E);
//     idt_set_gate(13, (uint32_t)isr13, 0x08, 0x8E);
//     idt_set_gate(14, (uint32_t)isr14, 0x08, 0x8E);
//     idt_set_gate(15, (uint32_t)isr15, 0x08, 0x8E);
//     idt_set_gate(16, (uint32_t)isr16, 0x08, 0x8E);
//     idt_set_gate(17, (uint32_t)isr17, 0x08, 0x8E);
//     idt_set_gate(18, (uint32_t)isr18, 0x08, 0x8E);
//     idt_set_gate(19, (uint32_t)isr19, 0x08, 0x8E);
//     idt_set_gate(20, (uint32_t)isr20, 0x08, 0x8E);
//     idt_set_gate(21, (uint32_t)isr21, 0x08, 0x8E);
//     idt_set_gate(22, (uint32_t)isr22, 0x08, 0x8E);
//     idt_set_gate(23, (uint32_t)isr23, 0x08, 0x8E);
//     idt_set_gate(24, (uint32_t)isr24, 0x08, 0x8E);
//     idt_set_gate(25, (uint32_t)isr25, 0x08, 0x8E);
//     idt_set_gate(26, (uint32_t)isr26, 0x08, 0x8E);
//     idt_set_gate(27, (uint32_t)isr27, 0x08, 0x8E);
//     idt_set_gate(28, (uint32_t)isr28, 0x08, 0x8E);
//     idt_set_gate(29, (uint32_t)isr29, 0x08, 0x8E);
//     idt_set_gate(30, (uint32_t)isr30, 0x08, 0x8E);

//     idt_flush((uint32_t)&idt_ptr);
// }

// void idt_set_gate(unsigned char num, uint32_t base, uint16_t sel, unsigned char flags) {
//     idt_entries[num].base_lo = base & 0xFFFF;
//     idt_entries[num].base_hi = (base >> 16) & 0xFFFF;

//     idt_entries[num].sel     = sel;
//     idt_entries[num].always0 = 0;
//     idt_entries[num].flags   = flags /* | 0x60 */;
// } 
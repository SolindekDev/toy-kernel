#pragma once

#include <stdint.h>

#define NO_GDT_DESCRIPTORS     8

typedef struct {
   uint16_t segment_limit;
   uint16_t base_low;      
   uint8_t base_middle;    
   uint8_t access;          
   uint8_t granularity;     
   uint8_t base_high;      
} __attribute__((packed)) GDT;

typedef struct {
   uint16_t limit;       
   uint32_t base_address;  
} __attribute__((packed)) GDT_PTR;

extern void load_gdt(uint32_t gdt_ptr);

void gdt_set_entry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

void gdt_init();

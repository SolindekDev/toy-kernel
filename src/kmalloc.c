#include <multiboot.h>
#include <graphics.h>
#include <kmalloc.h>
#include <print.h>
#include <stdint.h>

uint64_t start_memory_addr;
uint64_t actual_memory_addr;

void init_memory_managment(MULTIBOOT_INFO* mboot_info) {
    start_memory_addr = mboot_info->mmap_addr;
}

// void* kmalloc(int size) {
//     for (int i = actual_memory_addr; i < size; i++) {

//     }
// }

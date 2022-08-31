#include <smbios.h>
#include <ports.h>
#include <entry.h>
#include <utils.h>

SMBIOSEntryPoint* smbios_structure;

void smbios_init() {
    char* mem = (unsigned char*)SMBIOS_START_MEMORY;
    int length, i;
    unsigned char checksum;

    while ((unsigned int)mem < SMBIOS_END_MEMORY) {
        if (mem[0] == '_' && mem[1] == 'S' && mem[2] == 'M' && mem[3] == '_') {
            length = mem[5];
            checksum = 0;
            for (i = 0; i < length; i++)
                checksum += mem[i];
            if (checksum == 0) break;
        }
        mem += 16;
    }

    if ((unsigned int)mem == SMBIOS_END_MEMORY) {
        err_print("SMBIOS not found\n");
    } else {
        smbios_structure = (SMBIOSEntryPoint*)mem;
        ok_print("SMBIOS initialized\n");
    }
}

SMBIOSEntryPoint* get_smbios_structure() {
    return smbios_structure;
}
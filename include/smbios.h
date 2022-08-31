#pragma once

#include <stdbool.h>

#define SMBIOS_START_MEMORY 0xF0000
#define SMBIOS_END_MEMORY   0x100000

typedef struct SMBIOSEntryPoint {
 	char EntryPointString[4]; 
 	unsigned char Checksum;              
 	unsigned char Length;                
 	unsigned char MajorVersion;         
 	unsigned char MinorVersion;          
 	unsigned short MaxStructureSize;     
 	unsigned char EntryPointRevision;    
 	char FormattedArea[5];       
 	char EntryPointString2[5];   
 	unsigned char Checksum2;             
 	unsigned short TableLength;          
 	unsigned int TableAddress;	    
 	unsigned short NumberOfStructures;   
 	unsigned char BCDRevision;           
} SMBIOSEntryPoint;

void smbios_init();
SMBIOSEntryPoint* get_smbios_structure();
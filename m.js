for (let i = 0; i < 31; i++)
    console.log(`idt_set_gate(${i}, (uint32_t)isr${i}, 0x08, 0x8E);`)
struct InterruptDescriptor32 {
   uint16_t offset_1;        // offset bits 0..15
   uint16_t selector;        // a code segment selector in GDT or LDT
   uint8_t  zero;            // unused, set to 0
   uint8_t  type_attributes; // gate type, dpl, and p fields
   uint16_t offset_2;        // offset bits 16..31
};

void idt_set_gate(int num, uint32_t base, uint16_t selector, uint8_t type_attributes) {
   idt[num].offset_1 = base & 0xFFFF;
   idt[num].offset_2 = (base >> 16) & 0xFFFF;
   idt[num].selector = selector;
   idt[num].zero = 0;
   idt[num].type_attributes = type_attributes;
}
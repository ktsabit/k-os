#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "sys.c"
#include "vga.c"
#include "gdt.c"
 
void _main(void) 
{
	init_vga();
	set_text_color(0xf, 0);
		puts("Welcome to k-OS!\n");
	
	init_gdt();
	puts("GDT initialized\n");
}

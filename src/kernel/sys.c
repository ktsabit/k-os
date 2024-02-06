#include "sys.h"

// unsigned char inb(unsigned short port)
// {
// 	unsigned char ret;
// 	__asm__("inb %1, %0" : "=a"(ret) : "dN"(port));
// 	return ret;
// }

// void outb(unsigned short port, unsigned char data)
// {
// 	__asm__("outb %1, %0" :: "dN"(port), "a"(data));
// }

unsigned char* memcpy(unsigned char* dst, const unsigned char* src, int cnt)
{
	int i = 0;

	for (; i < cnt; i++)
		dst[i] = src[i];

	return dst;
}

unsigned char* memset(unsigned char* dst, unsigned char val, int cnt)
{
	int i = 0;

	for (; i < cnt; i++)
		dst[i] = val;

	return dst;
}

unsigned short* memsetw(unsigned short* dst, unsigned short val, int cnt)
{
	int i = 0;

	for (; i < cnt; i++)
		dst[i] = val;

	return dst;
}

int strlen(const char* str)
{
	int i = 0;

	while (str[i] != (char)0)
		i++;

	return i;
}

unsigned char inb(unsigned short port)
{
	unsigned char ret;
	// asm volatile("inb %%dx, %%al" : "=a"(ret) : "dN"(port));
    __asm__ volatile ( "inb %w1, %b0"
                   : "=a"(ret)
                   : "Nd"(port)
                   : "memory");
    
	return ret;
}

void outb(unsigned short port, unsigned char data)
{
	// asm volatile("outb %%al, %%dx" :: "dN"(port), "a"(data));
    __asm__ volatile ( "outb %b0, %w1" : : "a"(data), "Nd"(port) : "memory");
}



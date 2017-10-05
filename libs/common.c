#include "common.h"

// 端口写一个字节
inline void outb (uint16_t port, uint8_t value)
{
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

// 端口读一个自己
inline uint8_t intb (uint16_t port)
{
	uint8_t ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

// 端口读两个字节
inline uint16_t intw (uint16_t port)
{
	uint16_t ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}
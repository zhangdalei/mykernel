#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#include "types.h"

// 端口写一个字节
void outb(uint16_t port, uint8_t value);

// 端口读一个字节
uint8_t intb(uint16_t port);

// 端口读一个字，即两个字节
uint16_t intw(uint16_t port);

#endif
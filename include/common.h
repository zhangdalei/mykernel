#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#include "types.h"

// �˿�дһ���ֽ�
void outb(uint16_t port, uint8_t value);

// �˿ڶ�һ���ֽ�
uint8_t intb(uint16_t port);

// �˿ڶ�һ���֣��������ֽ�
uint16_t intw(uint16_t port);

#endif
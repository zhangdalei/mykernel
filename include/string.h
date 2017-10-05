#ifndef _INCLUDE_STRING_H
#define _INCLUDE_STRING_H

#include "types.h"
// 内存拷贝
void memcpy(void *dest, const void *src, uint32_t len);

// 设置内存值
void memset(void *dest, uint8_t c, uint32_t len);

// 设置s开始地址的前n字节为0
void bzero(void *s, uint32_t n);

uint32_t strlen(const char *s);

int strcmp(const char *s1, const char *s2);

#endif
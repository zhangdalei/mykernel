#ifndef _INCLUDE_STRING_H
#define _INCLUDE_STRING_H

#include "types.h"
// �ڴ濽��
void memcpy(void *dest, const void *src, uint32_t len);

// �����ڴ�ֵ
void memset(void *dest, uint8_t c, uint32_t len);

// ����s��ʼ��ַ��ǰn�ֽ�Ϊ0
void bzero(void *s, uint32_t n);

uint32_t strlen(const char *s);

int strcmp(const char *s1, const char *s2);

#endif
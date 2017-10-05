#include "string.h"

// �ڴ濽��
inline void memcpy(void *dest, const void *src, uint32_t len)
{
	uint8_t* des = (uint8_t*)dest;
	uint8_t* sc = (uint8_t*)src;
	for (; len != 0; len--)
	{
		*des++ = *sc++;
	}
}

// �����ڴ�ֵ
inline void memset(void *dest, uint8_t c, uint32_t len)
{
	uint8_t* des = (uint8_t*)dest;
	for (; len != 0; len--)
	{
		*des++ = c;
	}
}

// ����s��ʼ��ַ��ǰn�ֽ�Ϊ0
inline void bzero(void *s, uint32_t n)
{
	memset(s, 0, n);
}

uint32_t strlen(const char *s)
{
	uint32_t len = 0;
	while (*s++ != '\0')
		++len;
	return len;
}

inline int strcmp(const char *s1, const char *s2)
{
	if (strlen(s1) != strlen(s2))
		return 1;
	while (*s1 != '\0'){
		if (*s1++ != *s2++)
			return 1;
	}
	return 0;
	
}
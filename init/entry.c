#include "types.h"
#include "console.h"
#include "string.h"
#include "debug.h"

int kern_entry ()
{
	uint8_t *input = (uint8_t *)0xB8000;
	// uint8_t color = (0 << 4) | (15 & 0x0F);
	uint8_t color = 0x4F;
	char *s = "zhangdalei";
	char *s1 = "zhangdalei0";
	char dest[20];
	int len = 0;
	init_debug();
	*input++ = 'H'; *input++ = color;
	*input++ = 'e'; *input++ = color;
	*input++ = 'l'; *input++ = color;
	*input++ = 'l'; *input++ = color;
	*input++ = 'o'; *input++ = color;
	*input++ = ','; *input++ = color;
	*input++ = ' '; *input++ = color;
	*input++ = 'O'; *input++ = color;
	*input++ = 'S'; *input++ = color;
	*input++ = ' '; *input++ = color;
	*input++ = 'K'; *input++ = color;
	*input++ = 'e'; *input++ = color;
	console_clear();
	console_write_color(s, rc_blue, rc_white);
	print_stack_trace();
	memcpy(dest, s, 11);
	console_write_color(dest, rc_white, rc_blue);
	
	//memset(dest, '0', 5);
	//console_write_color(dest, rc_blue, rc_white);
	printk("\n");
	len = strlen(s);
	printk("strlen:%d\n",len);
	
	if (!strcmp (s, s1))
		printk("s and s1 is equal.\n");
	else
		printk("s and s1 is not equal.\n");
	return 0;
} 
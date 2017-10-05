/*
 *  控制屏幕字符和字符串输出函数
 */
#include "console.h"
#include "common.h"

// VGA的显示缓冲起始地址 0XB8000
static uint16_t *text_memory = (uint16_t*)0xB8000;

// 屏幕光标位置，指定输出位置
static uint8_t cursor_x = 0;
static uint8_t cursor_y = 0;

// 移动光标位置
static void move_cursor ()
{
	// 屏幕是80字节宽
	uint16_t cursorLocation = cursor_y * 80 + cursor_x;
	
	/** 这里用到两个外部寄存器，分别写入14,15，表示设置光标位置 */
	outb(0x3D4, 14); 					// 告诉VGA 我们要设置光标的高字节
	outb(0x3D5, cursorLocation >> 8); 	// 发送高8 位
	outb(0x3D4, 15); 					// 告诉VGA 我们要设置光标的低字节
	outb(0x3D5, cursorLocation); 		// 发送低8 位
}

/** 清屏操作 */
void console_clear ()
{
	int i = 0;
	uint16_t blank = (0x0F << 8) | 0X20;	// 背景色为黑色，前景色为白色
	for (i = 0; i < 80*25; i++)
	{
		//*text_memory = blank;			
		//text_memory += 1;
		text_memory[i] = blank;
	}
	cursor_x = 0;
	cursor_y = 0;
	move_cursor();
	/* 使用指针方式，需要重新赋值text_memory为0xB8000，后面还要用这个值 */
	//text_memory = (uint16_t*)0xB8000;
}

/** 屏幕滚动 */
static void scroll ()
{
	int i=0;
	uint16_t blank = (0x0F << 8) | 0X20;
	if (cursor_y >= 25)
	{
		// 从24行开始，将每一行向上移动一行
		for(i = 0; i < 25*80; i++)
			text_memory[i] = text_memory[i+80];
		
		// 最后一行清空
		for(i = 0; i < 80; i++)
		{	
			text_memory[80*24 + i] = blank;
		}
		cursor_y = 24;
	}
}

/** 输出带颜色的字符串 */
void console_putc_color (char c, real_color_t back, real_color_t fore)
{
	//uint16_t *textLocation = (uint16_t*)text_memory + (cursor_y * 80 + cursor_x);
	uint8_t back_color = (uint8_t)back;
	uint8_t fore_color = (uint8_t)fore;
	
	uint8_t color = (back_color << 4) | (fore_color & 0X0F);
	uint16_t attribute = color << 8;
	// 0x08 是退格键的ASCII 码
	// 0x09 是tab 键的ASCII 码
	if (c == 0x08 && cursor_x) {
		cursor_x--;
	} else if (c == 0x09) {
		cursor_x = (cursor_x+8) & ~(8-1);
	} else if (c == '\r') {
		cursor_x = 0;
	} else if (c == '\n') {
		cursor_x = 0;
		cursor_y++;
	} else if (c >= ' ') {
		text_memory[cursor_y*80 + cursor_x] = c | attribute;
		cursor_x++;
	}
	
	// 输入位置已经在一行最后，就换行
	if((cursor_x + 1) >= 80 )
	{
		cursor_y += 1;
		cursor_x = 0;
	}
	scroll();
	move_cursor();
}

// 屏幕打印一个以 '\0'结尾的字符串，默认黑底白字
void console_write (char *cstr)
{
	while(*cstr)
		console_putc_color(*cstr++, rc_black, rc_white);
}

void console_write_color (char *cstr, real_color_t back, real_color_t fore)
{
	while(*cstr)
		console_putc_color(*cstr++, back, fore);
}



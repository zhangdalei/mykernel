#ifndef _INCLUDE_DEBUG_H
#define _INCLUDE_DEBUG_H

#include "console.h"
#include "vargs.h"
#include "elf.h"

#define assert(x, info) 					\
	do { 									\
		if (!(x)) { 						\
		panic(info); 						\
	} 										\
	} while (0)

// 编译期间静态检测
#define static_assert(x) 					\
	switch (x) { case 0: case (x): ; }
		
// 初始化Debug 信息
void init_debug();

// 打印函数栈
void print_stack_trace();

// 打印当前的函数调用栈信息
void panic(const char *msg);

// 打印当前的段存器值
void print_cur_status();

void printk(const char *format, ...);

#endif

#include "main.h"

int print_memory_address(va_list args)
{
	void *ptr = va_arg(args, void *);
	int len = 0;

	printf("0x");
	len += 2;
	for (int i = 7; i >= 0; i--)
	{
	unsigned char byte = (unsigned char)(((uintptr_t)ptr >> (i * 8)) & 0xFF);

	printf("%02X", byte);
	len += 2;
	}
	return (len);
}

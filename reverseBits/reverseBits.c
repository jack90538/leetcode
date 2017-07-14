/*
Reverse Bits
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
Follow up:
If this function is called many times, how would you optimize it?

*/

#include <stdio.h>
#include <stdint.h>


uint32_t reverseBits(uint32_t n)
{
	uint32_t ret = 0;
	int i;

	for(i = 0; i < 32; i++)
	{
		ret = ret<<1 | n&0x1;
		n = n >> 1;
	}

	return ret;
}

int main()
{
	uint32_t num = 0;
	uint32_t result = 0;
	
	printf("enter num:");
	scanf("%u", &num);
	result = reverseBits(num);
	
	printf("num %x result %x\n", num, result);

	return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct data_s{
	struct data_s * ptr;
	char val[100];
} data_t;

#define mysizeof(type) ((&type+1)-&type)
//#define mysizeof(type) (char *)(&type+1)-(char*)(&type)

int main()
{
	data_t data;
	
	printf("result %d\n", mysizeof(data));
	
	return 0;
}

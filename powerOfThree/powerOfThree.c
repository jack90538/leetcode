/* Power of Three */
/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/
#include <stdio.h>


int isPowerOfThree(int n)
{
	int result = 0;
	int number = 1;
	
	while(number <= n && number >= 0)	/* check number >= 0 to avoid overflow */
	{
		if(number == n)
			result = 1;
		number = number*3;
	}
	
	return result;
}


int main()
{
	int n;
	int result;
	
	printf("enter n:");
	scanf("%d", &n);

	result = isPowerOfThree(n);
	printf("n = %d, result %d\n", n, result);

	return 0;
}

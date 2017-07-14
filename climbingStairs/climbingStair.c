#include <stdio.h>

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
int climbStairs(int n) {
	static int answer[1000] = {0};
	int result = 0;
	
	if(n == 0)
	{
		return 0;
	}
	else if(n == 1)
	{
		return 1;
	}
	else if(n == 2)
	{
		return 2;
	}
	// if we compute result before, use it, not comput again
	else if(n < 1000 && answer[n])
	{
		return answer[n];
	}
	else
	{
		result = climbStairs(n-1) + climbStairs(n-2);
		// store comput result for other use in same case 
		if(n < 1000)
		{
			answer[n] = result;
		}
		return result;
	}

	return 0;
}


int main()
{
	int n;
	int result;
	
	printf("enter n:");
	scanf("%d", &n);

	result = climbStairs(n);

	printf("n %d result is %d\n", n, result);

	return 0;
}


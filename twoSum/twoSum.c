

/* Two Sum */
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
	int i;
	int j;
	int *ret;
	
	for(i = 0; i < numsSize; i++)
	{
		for(j = i+1; j < numsSize; j++)
		{
			if(nums[i] + nums[j] == target)
			{
				ret = malloc(sizeof(int)*2);
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}

	return NULL;
}


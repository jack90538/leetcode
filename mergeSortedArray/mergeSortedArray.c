/*
Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

void shiftElement(int *nums1, int size, int targetIndex)
{
	int i;
	
	for(i=size-1; i>=targetIndex; i--)
	{
		nums1[i+1] = nums1[i];
	}
}

void merge(int* nums1, int m, int* nums2, int n)
{
	int i;	/* index of nums1 */
	int j;	/* index of nums2 */
	int found = false;
	
	for(j = 0; j < n; j++)
	{
		found = false;
		for(i = 0; i < m+j && !found; i++)
		{
			if(nums2[j] < nums1[i])
			{
				/* insert before nums1[i] */
				shiftElement(nums1, m+j, i);
				nums1[i] = nums2[j];
				found = true;
			}
		}

		if(!found)
		{
			nums1[m+j] = nums2[j];
		}
	}
}


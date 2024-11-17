#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int size = nums1Size + nums2Size;
    int *mergeArray = (int *)malloc(size * sizeof(int));
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
            mergeArray[k++] = nums1[i++];
        else
            mergeArray[k++] = nums2[j++];
    }

    while (i < nums1Size)
        mergeArray[k++] = nums1[i++];

    while (j < nums2Size)
        mergeArray[k++] = nums2[j++];

    if (size % 2 == 0)
        return ((mergeArray[size / 2 - 1] + mergeArray[size / 2]) / 2.0);
    else
        return mergeArray[size / 2];
}

int main()
{
    int nums1[] = {1, 3, 4};
    int nums2[] = {2, 5, 7};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    return 0;
}

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
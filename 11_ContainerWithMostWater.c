#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxArea(int *height, int heightSize)
{
    int maxSize = 0;
    int minBar = 0;

    for (int i = 0; i < heightSize; i++)
    {
        for (int j = i + 1; j < heightSize; j++)
        {
            minBar = height[i] < height[j] ? height[i] : height[j];
            
            int currentArea = minBar * (j - i);
            if (currentArea > maxSize)
            {
                maxSize = currentArea;
            }
        }
    }

    return maxSize;
}

int main()
{
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = maxArea(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}
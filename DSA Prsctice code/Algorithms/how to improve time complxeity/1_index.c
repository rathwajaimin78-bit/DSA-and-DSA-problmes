#include <stdio.h>
int main()
{
    int nums[] = {1, 13, 3, 10, 5, 6};
    int nums_lenth = sizeof(nums) / sizeof(int);
    int target = 12;

    int exit = 0;
    for (int i = 0; i < nums_lenth - 1; i++)
    {
        for (int j = i + 1; j < nums_lenth; j++)
        {
            if (nums[j] >= target - nums[i])
            {
                printf("[%d , %d] \n", i, j);
                exit = 1;
                break;
            }
        }

        if (exit == 1)
        {
            break;
        }
    }

    return 0;
}
//  // worst case time complexity O(n^2)
/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

// Constraints:
//
// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
// Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
#include <stdio.h>
#include <stdlib.h>
typedef struct number
{
    int data;
    int index;
} num;

// shoring algorthm
int partition(num *array, int low, int high)
{

    int pivot = array[low].data;
    int i = low + 1, j = high, tamp;
    do
    {
        while (array[i].data <= pivot)
        {
            i++;
        }
        while (array[j].data > pivot)
        {
            j--;
        }
        if (i < j)
        {
            tamp = array[i].data;
            array[i].data = array[j].data;
            array[j].data = tamp;
        }
    } while (i < j);
    tamp = array[low].data;
    array[low].data = array[j].data;
    array[j].data = tamp;

    return j;
}
void Quick_sort_algorithm(num *array, int low, int high)
{
    int partition_index;
    if (low < high)
    {
        partition_index = partition(array, low, high);

        Quick_sort_algorithm(array, low, partition_index - 1);
        Quick_sort_algorithm(array, partition_index + 1, high);
    }
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int nums_length = sizeof(nums) / sizeof(int);
    int target = 17;

    num *array = (num *)malloc(nums_length * sizeof(num));
    for (int i = 0; i < nums_length; i++)
    {
        array[i].data = nums[i];
        array[i].index = i;
    }

    Quick_sort_algorithm(array, 0, nums_length - 1);

    int left = 0;
    int right = nums_length - 1;

    while (right > left)
    {
        int currunt_sum = array[right].data + array[left].data;
        if (currunt_sum == target)
        {
            printf("[%d , %d] \n", left, right);
            return 0;
        }
        else if (currunt_sum < target)
        {
            left++; // go for larger number
        }
        else
        {
            right--; // go smaller number
        }
    }

    free(array);
    return 0;
}

// worst case time complexity O(nlog(n))

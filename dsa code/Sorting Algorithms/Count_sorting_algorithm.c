/*  The algorithm first asks you to find the largest element from all the elements in the array and store it in some integer variable max. Then create a count array of size max+1. This array would count the no. of occurrences of some number in the given array. We will have to initialize all count array elements with 0 for that to work.
After initializing the count array, traverse through the given array, and increment the value of that element in the count array by 1. By defining the size of the count array as the maximum element in the array, you ensure that each element in the array has its own corresponding index in the count array. After we traverse through the whole array, we’ll have the count of each element in the array.
Now traverse through the count array, and look for the nonzero elements. The moment you find an index with some value other than zero, fill in the sorted array the index of the non-zero element until it becomes zero by decrementing it by 1 every time you fill it in the resultant array. And then move further.
*/
#include <stdio.h>
#include <stdlib.h>

int find_max_value(int array[], int size) // give maximum value
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf(" \n");
}

void count_sort_algorithm(int array[], int size)
{
    int max_value = find_max_value(array, size);
    int *count_array = (int *)calloc(max_value + 1, sizeof(int)); // calloc give 0 at starting values

    //  Increment the corresponding index in the count array
    for (int i = 0; i < size; i++)
    {
        count_array[array[i]]++;
    }

    // wirting back on main array
    int i = 0, j = 0;
    while (i <= max_value)
    {
        if (count_array[i] > 0)
        {
            array[j] = i;
            count_array[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }

    printf("array shorted  \n");
}

int main()
{
    int array[] = {3, 1, 9, 7, 1, 2, 4}; // you can add your values
    int size = 7;
    print_array(array, size);

    count_sort_algorithm(array, size);

    print_array(array, size);

    return 0;
}
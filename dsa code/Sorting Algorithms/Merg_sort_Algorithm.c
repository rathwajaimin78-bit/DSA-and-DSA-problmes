#include <stdio.h>
#include <stdlib.h>
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf(" \n");
}
int Mreging(int array[], int low, int mid, int high) // Mreag two array 
{ //
    int i = low, j = mid + 1, k = low;
    // int b[high +1] ;
    // int b[100];
    int *b = (int *)malloc((high + 1) * sizeof(int)); //
    while (i <= mid && j <= high)
    {
        // arnging by value 
        if (array[i] < array[j])
        {
            b[k] = array[i];
            i++;
            k++;
        }
        else
        {
            b[k] = array[j];
            j++;
            k++;
        }
    }
// now arnging reming array element 
    while (i <= mid)
    {
        b[k] = array[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = array[j];
        j++;
        k++;
    }
    // copy back into array 
    for (int i = low; i <= high; i++)
    {
        array[i] = b[i];

    }

    return 0;
}
void Merg_sort_algorithm(int array[], int low, int high) // divide array on two possible equle parts (recursivly )
{
    int mid;
    if (low < high)
    {

        mid = (low + high) / 2;
        Merg_sort_algorithm(array, low, mid);
        Merg_sort_algorithm(array, mid + 1, high);
        Mreging(array, low, mid, high);
    }
}

int main()
{

    //             3  5  2  13 12 3 2 13 45
    int array[] = {3, 5, 2, 13, 12, 3, 2, 13, 45}; // you can add your values
    int size = 9;
    print_array(array, size);

    Merg_sort_algorithm(array, 0, size - 1);
    printf("array shorted  \n");
    print_array(array, size);

    return 0;
}
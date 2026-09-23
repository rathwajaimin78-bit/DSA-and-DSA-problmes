
// 4. Median of Two Sorted Arrays

#include <stdio.h>

float mindeun_form_two_array(int A[], int B[], int size_of_A, int size_of_B)
{

    int size_of_array = size_of_A + size_of_B;
    int array[size_of_array];

    int j = 0;
    int i = 0;
    int index = 0;
    while (i < size_of_A || j < size_of_B)
    {
        if (A[i] < B[j])
        {
            array[index] = A[i];
            i++;
        }
        else if (A[i] > B[j])
        {
            array[index] = B[j];
            j++;
        }
        else
        {
            array[index] = A[i];
            array[index] = B[j];
            i++;
            j++;
        }

        index++;
    }
    while (i <= size_of_A)
    {
        array[index] = A[i];
        i++;
        index++;
    }
    while (j <= size_of_B)
    {
        array[index] = B[j];
        j++;
        index++;
    }

    float mid;
    if (size_of_array % 2 == 0)
    {
        mid = (array[size_of_array / 2] + array[(size_of_array / 2) - 1]) / 2.0;
    }
    else
    {

        mid = (array[size_of_array / 2] + array[(size_of_array / 2)]) / 2.0;
    }

    // finding mideun
    return mid;
}

int main()
{
    int A[] = {1, 2};
    int B[] = {3, 4, 5};

    int size_A = sizeof(A) / sizeof(int);
    int size_B = sizeof(B) / sizeof(int);

    // printf("%d , %d \n", size_A, size_B);

    float mindeun = mindeun_form_two_array(A, B, size_A, size_B);
    printf("%g \n", mindeun);

    return 0;
}
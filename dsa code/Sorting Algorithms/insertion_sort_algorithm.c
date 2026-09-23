#include <stdio.h>
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf(" \n");
}
void insertion_sort_algorithm(int array[], int size)
{
    int key; // entering value
    int j = 0;

    for (int i = 0; i <= size - 1; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    printf("array shorted  \n");
}

int main()
{
    // index    -1  0   1   2 |  3   4   5   6   7  8   9  10
    //              2  44  67 | 33  12  99  45  22  3   7  54
    int array[] = {2, 44, 67, 33, 12, 99, 45, 22, 3, 78, 54}; // you can add your values
    int size = 11;
    print_array(array, size);

    insertion_sort_algorithm(array, size);

    print_array(array, size);

    return 0;
}
// insertion short explane
/*  index    -1 | 0   1   2   3   4   5   6   7  8   9  10 i = 0 , j =  -1
                | 2  44  67  33  12  99  45  22  3   7  54 key = 2

    index    -1  0  | 1   2   3   4   5   6   7  8   9  10 i = 1 , j = 0
                 2  |44  67  33  12  99  45  22  3   7  54 key = 44

    index    -1  0   1  | 2   3   4   5   6   7  8   9  10 i = 2, j = 1
                 2  44  |67  33  12  99  45  22  3   7  54 key = 67



    index    -1  0   1   2  | 3   4   5   6   7  8   9  10 i =3 , j = 2
                 2  44  67  |33  12  99  45  22  3   7  54 key = 33

    index    -1  0   1   2   3  | 4   5   6   7  8   9  10 i = 4, j = 3
                 2   33  44  67 |12  99  45  22  3   7  54 key = 12

    index    -1  0   1   2   3   4 |  5   6   7  8   9  10 i = 4, j = 3
                 2   12  33  44 67 | 99  45  22  3   7  54 key = 99
                 
    index    -1  0   1   2   3   4   5 |  6   7  8   9  10 i = 4, j = 3
                 2   12  33 44  67  99 | 45  22  3   7  54 key = 45

    index    -1  0   1   2   3   4   5   6 |   7  8   9  10 i = 4, j = 3
                 2   12  33 44  45  67  99 |  22  3   7  54 key = 22

    index    -1  0   1   2   3   4   5   6   7| 8   9  10 i = 4, j = 3
                 2   12  22  33 44  45  67  99| 3   7  54 key = 3

                 


    */
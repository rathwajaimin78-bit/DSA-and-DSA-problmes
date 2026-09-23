#include <stdio.h>
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf(" \n");
}
void selection_sort_algorithm(int array[], int size)
{ int minmum_index ;
    int tamp ;
    for (int i = 0; i < size -1; i++)
    {minmum_index = i ;
        for (int j = i+1; j < size ; j++)
        { 
            if (array[j] < array[minmum_index])
            { minmum_index = j ;
               
                
            }
          
        }//swaping element
        tamp = array[i] ;
        array[i] = array[minmum_index] ;
        array[minmum_index] = tamp;
    }
    

    printf("array shorted  \n");
}

int main()
{
    // index    -1  0  1  2  3  4   
    //              3  5  1  4  2  
    int array[] = {3,5,1,4,2}; // you can add your values
    int size = 5;
    print_array(array, size);

    selection_sort_algorithm(array, size);

    print_array(array, size);

    return 0;
}
 
// index    -1  0  1  2  3  4   
//             | 3  5  1  4  2

    // 1st pass
// index    -1  0   1  2  3  4   
//              1 | 5  3  4  2

    // 2nd pass
// index    -1  0  1   2  3  4   
//              1  2 | 3  4  5


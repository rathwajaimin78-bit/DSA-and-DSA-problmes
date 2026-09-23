// Bubble Sort Algorithm - the way data elements move through the list during the sorting process, which closely resembles air bubbles rising to the surface of wate


/*      sort by checking all pair of elemnts
    if they found upper index have value bigarr then lower then seap by lower to upper , if not swap this
    */
// adaptive
#include <stdio.h>
void print_array(int array[] , int size){
    for (int i = 0; i < size ; i++)
    {
        printf("%d ", array[i]);
    }
    printf(" \n");
    
}
void bubble_sort_algorithm(int array[] ,int size)
{
    int end = 1 ; // we can ran this till fully sort array
    int tamp;
    int pass = 0 ;
    int j=0;
   do
    { printf("pass %d \n", j++);
    
        for (int i = 0; i < size - 1 - pass; i++)
        {
            if (array[i] > array[i + 1])
            {
                tamp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tamp;

                end = 1;
            }
            else
            {
                end = 0;
            }
        } pass++;
    } while (end ); // 0 to end

    printf("array shorted  \n");
}

int main()
{
    int array[] = {2, 44, 67, 33, 12, 99, 45, 22 ,3 , 78, 54}; // you can add your values
    int size = 11;
    print_array(array , size);

    bubble_sort_algorithm(array , size);
    
    print_array(array , size);

    return 0;
}
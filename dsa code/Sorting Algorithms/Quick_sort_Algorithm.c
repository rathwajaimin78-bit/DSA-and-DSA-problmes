/*
1. Define i as the low index, which is the index of the first element of the subarray, and j as the high index, which is the index of the last element of the subarray.
 2.Set the pivot as the element at the low index i since that is the first index of the unsorted subarray.
 3.Increase i by 1 until you reach an element greater than the pivot element.
 4.Decrease j by 1 until you reach an element smaller than or equal to the pivot element.
 5.Having fixed the values of i and j, interchange the elements at indices i and j.
 6.Repeat steps 3, 4, and 5 until j becomes less than or equal to i.
 7.Finally, swap the pivot element and the element at the index.    */

#include <stdio.h>
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf(" \n");
}
int partition(int array[] , int low , int high){// arrange element ues pivot as refrenase  

    int pivot =array[low] ;
    int i = low+1 , j = high , tamp;
do{
    while (array[i]<= pivot) // find higher value
    {
        i++;
    }
    while (array[j]>pivot) // find value smalle or equle
    {
        j--;
    }
    if (i<j) // swap if i and j on ther condion
    {
        tamp = array[i] ;
        array[i] = array[j] ;
        array[j] = tamp ;
    }
}while(i<j);
        tamp = array[low] ;
        array[low] = array[j] ;
        array[j] = tamp ;
    
    return j ;
}
void Quick_sort_algorithm(int array[],int low , int high)
{ int partition_index ;
    if(low<high){ // condicion for array exitst
    partition_index = partition(array, low , high);

    Quick_sort_algorithm(array ,low, partition_index -1);
    Quick_sort_algorithm(array , partition_index +1 , high);
    
    }

    printf("array shorted  \n");
}

int main()
{
     
    //             3  5  2  13 12 3 2 13 45
    int array[] = {3, 5, 2 ,13,12,3,2,13,45}; // you can add your values
    int size = 8;
    print_array(array, size);

    Quick_sort_algorithm(array,0, size-1);

    print_array(array, size);

    return 0;
}
//Quick short explane 
/*  
    3p  5i  2  13  12 3 2 13 45j

    3p  5  2  13i  12 3 2j 13 45
    3p  5  2  2i   12 3 13j 13 45

    3p  5  2  2  12i 3j 13 13 45
    3p  5  2  2  3i 12j 13 13 45

    3p  5  2  2  3j 12i 13 13 45  i>j

    3i  5  2  2j  3p 12i 13 13 45j
    3i  5  2  2j  3p 12i 13 13 45j

    3i  5  2  2j  3p 12j 13 13 45i(not found <p)
    2i  5  2  3j  3p | 12 13 13 45 this side is shorted

    2  5i  2  3j  3p
    2  3i  2  5j  3p

    2  3  2j  5i  3p

    2j  3p  2  5p  3j
    

    2  2  3p  3i  5j | 12 13 13 45 shorting done!


    
*/
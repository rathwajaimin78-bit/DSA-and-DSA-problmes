/*total_size
used_size
base_address
And the operations include operators namely,

new array with this functnaitys
max()
get(i)
set(i,num)
add(another_array)*/

#include <stdio.h>
#include <stdlib.h>

typedef struct my_array
{
    int total_size_array; // memory resvaed
    int used_size_array;  // memory used
    int *base_address;    // 1st element

} m_array;

void create_array(m_array *array_name, int total_size, int used_size) // call  create_array(&name , max size , ues size)
{
    array_name->total_size_array = total_size;
    array_name->used_size_array = used_size;
    array_name->base_address = (int *)malloc(total_size * sizeof(int)); // daynmicale menory 
}

void get(m_array *name_array, int index) // call get( &array name ,index)
{

    printf(" index %d  %d \n", index, *(name_array->base_address + index));
}

void set(m_array *array, int n, int index) // call set(&array , value , index)
{

    *(array->base_address + index) = n;
}

//  int max(m_array* array  )
//  {

//  }

int main()
{
    m_array marks;

    int total_size = 15, used_size = 10;

    create_array(&marks, total_size, used_size);

    for (int i = 0; i < marks.used_size_array; i++)
    {
        set(&marks, i + 32, i);
    }

    for (int i = 0; i < marks.used_size_array; i++)
    {
        get(&marks, i);
    }

    // don't forget Memory Cleanup !
    free(marks.base_address); // it's good and must

    return 0;
}
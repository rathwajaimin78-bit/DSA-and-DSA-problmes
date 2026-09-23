/* An element at a specified position can be deleted, creating a void that needs to be fixed by shifting all the elements to their adjacent left
 */

#include <stdio.h>
int main()
{
    int array[15] = {1, 2, 3, 4, 5, 6, 7, 8};
    int used_size = 8;
    printf("array befor deletion  \n");
    for (int i = 0; i < used_size; i++)
    {
        printf("index %d : %d \n", i, array[i]);
    }

    int deleted_index = 7;

    for (int i = deleted_index; i < used_size; i++)
    {
        array[i] = array[i + 1];
    }
    used_size -= 1;
    
    printf("array after deletion  \n");
    for (int i = 0; i < used_size; i++)
    {
        printf("index %d : %d \n", i, array[i]);
    }

    return 0;
}
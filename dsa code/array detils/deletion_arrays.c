/* An element at a specified position can be deleted, creating a void that needs to be fixed by shifting all the elements to their adjacent left
*/

#include <stdio.h>
int main()
{
    int array[15] = {1,2,3,4,5,6,7,8} ;
    int used_size = 8 ;
    printf("array befor deletion  \n");
    for (int i = 0; i < used_size; i++)
    {
        printf("index %d : %d \n",i , array[i]);
        
    }

    int deleted_element = 2 ;

    for (int i = 0; i < used_size; i++)
    {
        if (array[i]==deleted_element)
        {
            for (int j = used_size; j < used_size; j++)
            {
                array[i] = array[i+1] ;
                i++;
            }
            break;
        }
        
        
    }
    used_size -= 1 ;

    printf("array after deletion  \n");
for (int i = 0; i < used_size; i++)
    {
        printf("index %d : %d \n",i , array[i]);
        
    }


    
    
    
return 0;
}
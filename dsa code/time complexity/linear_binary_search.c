#include <stdio.h>


void linear_search(int array[] , int size , int search_element){

    for (int i = 0; i < size; i++)
    {
        if (array[i]== search_element)
        {
            printf("%d element in this array at index %d \n", array[i] , i);
            goto new ;
        } 
    }    
   
         printf("%d element not in this array \n",search_element);
    
    new : ;
    
     
}
void binary_search(int array[] , int size , int search_element){
 int low = 0 , mid  , high = size-1 ;


    while (low<= high)
    {
        mid = (low + high)/2 ;

        if (array[mid]==search_element)
        {
           printf("%d element in this array %d \n", search_element , mid );
           goto end ;
        }
        
        if (search_element>array[mid])
        {
            low = mid +1 ;    
         }else{
            high = mid -1 ;
         }
    }
  
    printf("%d element not in this array \n",search_element);  
    end: 
    ;       
}
 

int main()
{
    int array[6] = {1,2,3,4,5,6} ;
    int size = sizeof(array)/sizeof(int) ;
   int element = 3 ;

   linear_search(array , size , element);
   binary_search(array , size , element);
    
    
return 0;
}
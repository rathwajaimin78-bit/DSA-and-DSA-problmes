#include <stdio.h>
#include <stdlib.h>

int f(int i){
    
}
int Hash_code(char key)
{
    int int_key = key;
    return int_key;
}
int comprsion(int key, int size)
{

    return key % size;
}

void insert_hash_map(char key, int *array, int value)
{

    int size = sizeof(array);
    key = Hash_code(key);
    int index = comprsion(key, size);
    if (array[index] != 0)
    {
        index = (index + f(index))%size ;
        // insert_hash_map(key , array , value);
        
    }else{
        array[index] = value;
    }

     

}

int search_Hash_map(char key, int *array)
{
    int size = sizeof(array);
    int int_key = Hash_code(key);
    int index = comprsion(int_key, size);

    return array[index];
}

int main()
{
    int array_size = 150;
    int *array = (int *)calloc(array_size , sizeof(int));
    insert_hash_map('r', array, 12);
    insert_hash_map('w', array, 11);
    insert_hash_map('y', array, 132);
    insert_hash_map('c', array, 172);

    char key = 'c';
    printf("%c key : %d \n", key, search_Hash_map(key, array));

    free(array);
    return 0;
}
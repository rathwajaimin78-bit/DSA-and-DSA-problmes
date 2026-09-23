/*Stack  Any operation on the stack is performed in LIFO (Last In First Out) order*/
// push(): to push an element into the stack
// pop(): to remove the topmost element from the stack

// all operation done in O(1) time complexity

#include <stdio.h>
#include <stdlib.h>
typedef struct Stack // like a storage
{
    int size;
    int top;  // using top element index 
    int *array; // dynimacliy memory first point address
} Stack;

void empty_or_not(Stack *point)
{

    if (point->top == -1)
    {
        printf("stack is empty ! \n");
    }
    else
    {
        printf("stack is not empty ! \n");
    }
}

void full_or_not(Stack *point)
{

    if (point->top == point->size - 1)
    {
        printf("stack is full ! \n");
    }
    else
    {
        printf("stack is not full ! \n");
    }
}

 void print_stack(Stack* storage){

      for (int i = 0; i < storage->top +1 ; i++)
    {
        printf("index %d : %d \n", i , storage->array[i]);
        
    }
    printf(" \n");
 }
int push(int value, Stack *name)
{

    if (name->top  == name->size )
    {
        full_or_not(name);
        printf("Stack overflow ! \n");
        return 0;
    }
    else
    {
        name->top = name->top + 1;  // incresing index
        (name->array[name->top]) = value;
        printf("successfully %d entered \n" , value);
        
    }
}
int pop( Stack *name){ // not completed , update completed !

    if (name->top == -1) // checking stack 
    {
        empty_or_not(name);
        return 0 ;
    }
    else
    {
        int delting_value = name->array[name->top] ;
         printf("successfully removed %d  \n" , name->array[name->top]);
        return name->top = name->top - 1 ; // decresing index 
        
    }
}

int main()
{
    Stack *storage = (Stack *)malloc( sizeof(Stack));
    storage->size = 6;
    storage->array = (int *)malloc(storage->size * sizeof(int));
    storage->top = -1;    // -1 show no elemnt remning(nothing any elment) after 0th elemnt 

    push(23, storage);  // input calls
    push(24, storage);
    push(25, storage);
    push(26, storage);
    push(27, storage);
    push(28, storage);
 // push(29 , storage); // overflow

  print_stack(storage);
    
    pop( storage); // delete elment


  print_stack(storage);
    free(storage->array);
    free(storage);
    return 0;
}
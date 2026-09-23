// Parenthesis Matching Problem Using Stack Data(array type) Structure (Applications of Stack)
/*check exprsion find braket
    if found ( throw in stack
    if found ) thow back out of stack this ( with this ) */
// end exprsion stack is emtey , so done Parenthesis Matched !
// at any posion we found first this ) then not Parenthesis Matched !

// ( ascii values 40
// ) ascii values 41
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack // like a storage
{
    int size;
    int top;    // using top element index
    int *array; // dynimacliy memory first point address
} Stack;

int empty_or_not(Stack *point)
{

    if (point->top == -1)
    {
        // printf("stack is empty ! \n");
        return 1;
    }
    else
    {
        // printf("stack is not empty ! \n");
        return -1;
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
void push(int value, Stack *name)
{if (name->top  == name->size )
    {
        full_or_not(name);
        printf("Stack overflow ! \n");
        
    }
    else
    {
        name->top = name->top + 1; // incresing index
    (name->array[name->top]) = value;
    // printf("successfully %d entered \n", value);
        
    }
    
}
int pop(Stack *name)
{ 
    if (name->top == -1) // checking stack
    {
        return 5;
    }
    else
    {
        int delting_value = name->array[name->top];
        // printf("successfully removed %d  \n", name->array[name->top]);
         name->top = name->top - 1; // decresing index
         return 0;
    } 
}

int Parenthesis_Matched(Stack *storage, char expresion[])
{
   
    for (int i = 0; i< strlen(expresion); i++)
    {
        if (expresion[i] == 41) // ) or not!
        {
            if (pop(storage) == 5){ return -1; }
            
           
        }
        if (expresion[i] == 40) // ( or not!
        {
            push(1, storage);
        } 
    }
    
    
    return empty_or_not(storage);
    
}
int main()
{
    Stack *storage = (Stack *)malloc(sizeof(Stack));
    storage->size = 50;
    storage->array = (int *)malloc(storage->size * sizeof(int));
    storage->top = -1;

    // input
    char expresion[20];
    printf("enter mathematcal equsion  \n");
    scanf("%19s", &expresion);

 int condtion = Parenthesis_Matched(storage, expresion) ;
    // out put
    if (condtion == 1)
    {
        printf("Parenthesis Matched ! \n");
    }
    else if (condtion == -1)
    {  
        printf("Parenthesis not Matched ! \n");
    }

    free(storage->array);
    free(storage);
    return 0;
}
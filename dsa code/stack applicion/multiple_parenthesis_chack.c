// Multipule Parenthesis Matching Problem Using Stack Data(array type) Structure (Applications of Stack)
/*check exprsion find braket
    if found ( throw in stack
    if found ) thow back out of stack this ( with this ) */
// end exprsion stack is emtey , so done Parenthesis Matched !
// at any posion we found first this ) then not Parenthesis Matched !

//  charter        (    )   {     }    [     ]
//  ascii values   40  41  123   125   91    93
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
        //  printf("stack is not empty ! \n");
        return -1;
    }
}
int search_elemnt(Stack* block , int x){
    
    if(empty_or_not(block) == 1)
    {
        return -5;
    }
    
        if (block->array[block->top] == x)
        {
            return 5 ;
        }
       return -5; 
    
    
}


void full_or_not(Stack *point)
{

    if (point->top == point->size - 1)
    {
        // printf("stack is full ! \n");
    }
    else
    {
        // printf("stack is not full ! \n");
    }

    
}
void push(int value, Stack *name)
{if (name->top  == name->size-1 )
    {
        full_or_not(name);
        // printf("Stack overflow ! \n");
        
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
            if (search_elemnt(storage , 1) == 5){ pop(storage); }else{ return -1;}

        }
        if (expresion[i] == 40) // ( or not!
        {
            push(1, storage);
        } 

        if (expresion[i] == 125) // } or not!
        {
            if (search_elemnt(storage , 2) == 5){ pop(storage); }else{ return -1;}
            
           
        }
        if (expresion[i] == 123) // { or not!
        {
            push(2, storage);
        }

        if (expresion[i] == 93) // ] or not!
        {
            if (search_elemnt(storage , 3) == 5){ pop(storage); }else{ return -1;}
            
           
        }
        if (expresion[i] == 91) // [ or not!
        {
            push(3, storage);
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
    char expresion[30];
    printf("enter mathematcal equsion  \n");
    scanf("%29s", &expresion);

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
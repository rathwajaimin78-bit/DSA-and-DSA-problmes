#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next; // self referncing structure
    struct node *previous;
} node;
typedef struct Stack // like a storage
{
    int size;
    int top;          // using top element index
    node *linked_list; // dynimacliy memory first point address
} Stack;

void full_or_not( Stack* name){
    if (name->top == name->size - 1)
    {
         printf("stack is full ! \n");
    }else{
        printf("stack is not full ! \n");
    }
    
}
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
void push(int value, Stack *name)
{
    if (name->top == name->size - 1)
    {
        full_or_not(name);
        printf("Stack overflow ! \n");
        
    }
    else
    {
        name->linked_list = (name->linked_list)->next ;
        name->linked_list->value  = value ;
        name->top++ ;
       
        printf("successfully %d entered \n", value);
    }
}

void pop(Stack* name){
    if (name->top == -1) // checking stack 
    {
        empty_or_not(name);
        
    }else{
        int delting_value = (name->linked_list)->value ;
         printf("successfully removed %d  \n" ,  (name->linked_list)->value );
         name->linked_list = name->linked_list->previous ; // decresing index 
         name->top--;
    }
}
int main()
{
    node *head;
    node *tharde;
    node *fist;
    node *secand;
    node *last;
    head = (node *)malloc(sizeof(node));
    fist = (node *)malloc(sizeof(node));
    secand = (node *)malloc(sizeof(node));
    tharde = (node *)malloc(sizeof(node));
    last = (node *)malloc(sizeof(node));

    head->next = fist;
    fist->next = secand;
    secand->next = tharde;
    tharde->next = last;
    last->next = NULL;
    // backward
    head->previous = NULL ;
    fist->previous = head ;
    secand->previous = fist ;
    tharde->previous = secand ;
    last->previous = tharde ;

    Stack *storage = (Stack *)malloc(4*sizeof(Stack));
    storage->size = 4;
    storage->linked_list = head;
    storage->top = -1;

    // full_or_not(storage);
    // empty_or_not(storage);
    push(3 , storage);
    push(2 , storage);
    push(4 , storage);
    push(5 , storage);
    push(6 , storage);

    pop(storage);
     free(storage);
    free(head);
    free(tharde);
    free(fist);
    free(last);
    free(secand);
   
    
    return 0;
}
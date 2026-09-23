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
    node *current_node; // dynimacliy memory first point address
} Stack;
 Stack* make_stack(){
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL ;
    head->previous = NULL ;
     new_stack->current_node = head ;
     new_stack->top = -1 ;
     return new_stack ;
 }
 void print_stack(Stack* printing){ // on going  , update - completed !
    node* N = printing->current_node ;
    if (printing->top == -1)
    {
        printf("nothing to print ! \n");
        
    }else{
        for( int i = printing->top ; i != -1 ; i--)
        {
           printf("index %d : %d \n" , i , N->value);
            N = N->previous ;
            
        }
        
        
    }
    
    
    
 }
void full_or_not( Stack* name){
    node* n =  (node*)malloc(sizeof(node)); ; 
    if (n == NULL)
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
        node* new_node = (node*)malloc(sizeof(node));
        new_node->next = NULL ;
        new_node->value = value ;
        new_node->previous = name->current_node ;
        name->current_node = new_node ;
        name->top++ ;
       
        printf("successfully %d entered \n", value);
    }
}

void pop(Stack* name){
    if (name->top == -1) // checking stack 
    {
        empty_or_not(name);
        
    }else{
        node* delting_value = name->current_node ;
        name->current_node = name->current_node->previous ;
        name->current_node->next =NULL ;
        name->top--;
        printf("successfully removed %d  \n" , delting_value->value);
        // decresing index 
        free(delting_value);
    }
}
 void peek(Stack* s , int posion){
    node* n = s->current_node ;
    for (int i = 0; i < posion -1 && n == NULL ; i++)
    {
        n = n->previous ;
    }
    if (n != NULL)
    {
        printf("%d elemnt at %d posion \n" , n->value , posion);
        
    }else{
        printf("posion not found ! \n");
        
    }
     
 }
 int top_most(Stack* S ){
    node* pointer_1 = S->current_node ;
    printf("to most value is %d \n" ,pointer_1->value);
    
    return pointer_1->value ;
 }
 int botom_most(Stack* S){
    node* pointer = S->current_node ;
    // printf("%d \n" , pointer->previous->value);
    
    while(pointer->previous->previous != NULL) //pointer at : null ,one time previous : hade , secande time previos : 1st node 
    {
        pointer = pointer->previous ;
        
    }
    
    printf("botom most value is %d \n" , pointer->value);
    
    return pointer->value ;
 }
void free_memory(Stack* name){
    node* now = name->current_node ;
    while (now == NULL)
    {
        node* tamp = now->previous ;
        free(now);
        now = tamp ;
    }
    free(name);
}
int main()
{
   Stack* storage =  make_stack();
    empty_or_not(storage);
    push(1 , storage);
    push(2 , storage);
    push(3 , storage);
    push(4 , storage);
    push(5 , storage);
    push(6 , storage);
  
   
   top_most(storage);
   botom_most(storage);
    return 0;
}
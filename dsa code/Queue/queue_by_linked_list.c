// Queue Using Linked List
/*  queue full - we can't able to request memory !
    queue empty - forntind = null
     */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value ;
    struct node *next ; // self referncing structure
} node;

typedef struct queue // like a storage
{
    int size;

    node *linked_list; // dynimacliy memory first point address
    node* frontind;
    node* backind;
} queue;

int empty_or_not(queue *point)
{

    if (point->frontind == NULL)
    {
        printf(" queue is empty ! \n");
        return 1;
    }
    else
    {
        printf(" queue is not empty ! \n");
        return 0 ;
    }
}

int full_or_not(queue *point)
{
   node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf(" queue is full ! \n");
        free(new_node);
        return 1;
    }
    else
    {
        printf(" queue is not full ! \n");
        free(new_node);
        return 0;
    }
}

int enqueue(int value, queue *name)
{

    if (full_or_not(name))
    {
        full_or_not(name);
        printf(" queue overflow ! \n");
        return 0;
    }
    else
    {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->value = value ;
        new_node->next = NULL ;
        if (name->frontind == NULL)
        {
            name->frontind = name->backind = new_node ;
        }else{
            name->backind->next = new_node ;
        name->backind = new_node ;
        }
         printf("successfully %d enqueued \n", value);
        
    }
}

int denqueue(queue *name)
{ 

    if (empty_or_not(name)) // checking queue
    {

        return 0;
    }
    else
    {
        node* deleting_node = name->frontind ;
        name->frontind = name->frontind->next ;
        printf("successfully denqueue %d  \n", deleting_node->value);
        free(deleting_node);
        return 0;
      
    }
}

void print_queue(queue* r){
int i = 1 ;
  node* tamp = r->frontind ;
    while (tamp != NULL)
    {
        
        printf("index %d : %d \n" ,i , tamp->value);
        tamp = tamp->next ;
    i++ ;
    }
    
    
}
int main()
{
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->linked_list =  (node *)malloc(Q->size * sizeof(node));

    Q->frontind = Q->backind = NULL ;
    
    enqueue(1 , Q);
    enqueue(2 , Q);
    enqueue(3 , Q);
    enqueue(4 , Q);
    print_queue(Q);
    denqueue(Q);
    print_queue(Q);

    free(Q->linked_list);
    free(Q);
return 0;
}


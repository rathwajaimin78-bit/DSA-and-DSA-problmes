#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value ;
    struct node *next ; // self referncing structure
} node;

void linked_list_traversal(node *start_point){
int i = 1 ;
    while (start_point != NULL)
    {
        printf("index %d : %d \n" ,i , start_point->value);
    start_point = start_point->next ;
    i++ ;
    }
    
    
}
// insertion in liked nodes
void linked_list_insalltion(node *start_point){
int i = 1 ;
    while (start_point != NULL)
    {
        printf("index %d :  \n" ,i );
        scanf("%d", &start_point->value);
    start_point = start_point->next ;
    i++ ;
    }
    
    
}
void linked_list_insaertion(node *start_point){
int i = 1 ;
    node *point = (node*)malloc(sizeof(node)) ;
    printf("new index value %d :  \n" ,i );
    scanf("%d" , point->value);
    point->next = start_point ;
    // linked_list_traversal(point);
}

int main()
{
    node* tharde ;
    node* fist ;
    node* secand ; 
    node* last ;
fist = (node*)malloc(sizeof(node)) ;
secand = (node*)malloc(sizeof(node)) ;
 tharde = (node*)malloc(sizeof(node)) ;
 last = (node*)malloc(sizeof(node)) ;


    fist->next = secand ;
    secand->next = tharde ;
    tharde->next = last ;
    last->next = NULL ;

    linked_list_insalltion(fist) ;

    linked_list_traversal(fist);
    linked_list_insaertion(fist) ;


    // adding new element

   free(tharde);
   free(fist);
   free(last);
   free(secand);
    
return 0;
}
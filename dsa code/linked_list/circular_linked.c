/* Circular Linked Lists
    Unlike singly-linked lists, a circular linked list has no node pointing to NULL. Hence it has no end. The last element points at the head node.
    All the operations can still be done by maintaining an extra pointer fixed at the head node.
    A circular linked list has a head node, but no starting node.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value ;
    struct node *next ; // self referncing structure
} node;

void linked_list_traversal(node *start_point){
int i = 1 ;
node* x = start_point ;
    
    do{
        printf("index %d : %d \n" ,i , start_point->value);
    start_point = start_point->next ;
    i++ ;
    }while (start_point != x);
    
}
// insertion in liked nodes
void linked_list_insalltion(node *start_point){
int i = 1 ;
node* x = start_point ;
    do{
        printf("index %d :  \n" ,i );
        scanf("%d", &start_point->value);
    start_point = start_point->next ;
    i++ ;
    }while (start_point != x);
    
}


void linked_list_deletion(node* starting_point){
int index ; int i =1 ;
node* p = starting_point;
node* garbag ;

    printf("enter node index to delete : \n");
    scanf("%d" , &index);

    while (i!=index-1)
    {
        p = p->next ;
        i++ ;
    }
     garbag = p->next  ;
    p->next = (p->next)->next ;
    

    free(garbag);


}


void linked_list_value_deletion(node* starting_point){
int value ; int index =1  ;
int i=1 ;
node* p = starting_point;
node* p2 = starting_point;
node* x = starting_point ;
node* garbag ;

    printf("enter value to delete : \n");
    scanf("%d" , &value);
    int found = 0 ;
    do{
        if (p->value == value)
        {
            found = 1 ;
            break;
        }
        p = p->next ;
        
        index++ ;
    }while (p != x);
    
    if (!found) // found is 1 then ! convert 0 and if is fales ,  found is 0 then ! convert 1 and if is true
    {
        printf("element not found ! \n");
        return;
    }
    

     do{
        p2 = p2->next ;
        i++ ;
    }while (i!=index-1);
    
     garbag = p2->next  ;
    p2->next = (p2->next)->next ;
    

    free(garbag);

    

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
    last->next = fist ;

    linked_list_insalltion(fist) ;
    linked_list_traversal(fist);

    // deleting element
    linked_list_value_deletion(fist);
    linked_list_traversal(fist);

   
      free(tharde);
   free(fist);
   free(last);
   free(secand);
return 0;
}
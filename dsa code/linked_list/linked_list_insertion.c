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
// insertion in likned nodes

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

// at starting
node* linked_list_insaertion(node *start_point){
int index = 1 ;
    node *point = (node*)malloc(sizeof(node)) ;
    printf("new index value %d :  \n" ,index );
    scanf("%d" , &point->value);
    point->next = start_point ; // added pointer point to old starting point  
    
    return point ;
}
// at index
node* linked_list_insaertion_given_index(node *start_point){
int index ,x ; int i=0 ;
    node *point = (node*)malloc(sizeof(node)) ;
    node *p = start_point;

    printf("index : value \n" );
    scanf("%d %d" , &index, &x);

    while (i!=index-1) //finding index
    {
        p = p->next ;
        i++ ;
    }
     point->value = x ;

    p->next = point ; // index-1 point to added node
    point->next = p->next ; // added node pointer point to next node
    
   return start_point ;
}
// at last
node* linked_list_insaertion_end(node *start_point){
int index ,x ;
    node *point = (node*)malloc(sizeof(node)) ;
    node *p = start_point;

    printf(" value at last \n" );
    scanf("%d" , &x);
point->value = x ;
    while (p->next!=NULL)
    {
        p = p->next ;
    }
     
    p->next=point  ; 
    point->next = NULL ;
   return start_point ;
}
// by point
void linked_list_insaertion_at_point(node *old_node){
int index ,x ;
    node *point = (node*)malloc(sizeof(node)) ;
  
    printf(" value at given point \n" );
    scanf("%d" , &x);
point->value = x ;

 old_node->next = point ;
 point->next = old_node->next ;

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
   node* new_point = linked_list_insaertion(fist) ;
    linked_list_traversal(new_point);



    // adding new element at given index

  linked_list_insaertion_given_index(fist);
    linked_list_traversal(fist);
 
 // adding element at end

 linked_list_insaertion_end(fist);
 linked_list_traversal(fist);
   
 // add elment at given pointer
  linked_list_insaertion_at_point(tharde);
 linked_list_traversal(fist);
    
   free(tharde);
   free(fist);
   free(last);
   free(secand);
return 0;
}
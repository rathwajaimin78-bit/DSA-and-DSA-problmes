#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int value ;
   struct node *left  ;
    struct node *right ; // self referncing structure
} node;

 int* make_node(int value){
    node* root_node = (node*)malloc(sizeof(node));
    root_node->value = value ;

    root_node->left = NULL ;
    root_node->right = NULL ;

    return root_node;
 }

 

int main()
{ 
 node* root_node = make_node(1);
 node* node_1 = make_node(2);
 node* node_2 = make_node(3);

 root_node->left = node_1;
 root_node->right = node_2;

return 0; 
}
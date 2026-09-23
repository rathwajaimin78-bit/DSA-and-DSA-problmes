// in inoder trsversal  - left->root->right

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right; // self referncing structure
} node;

node *make_node(int value)
{
    node *root_node = (node *)malloc(sizeof(node));
    root_node->value = value;

    root_node->left = NULL;
    root_node->right = NULL;

    return root_node;
}

void Inoder_traversal(node *base_node)
{ // recursive apprch help to solve fast binary tree

    if (base_node != NULL)
    {

        Inoder_traversal(base_node->left);
        printf("%d ", base_node->value);
        Inoder_traversal(base_node->right);
    }
}

int is_binary_search_tree(node *base_node)
{ 
    static node *prev = NULL; // static key word make sure line well execute only one time 
    if (base_node != NULL)   // checking tree exitence
    {
        if (!is_binary_search_tree(base_node->left)) // runing this function for left tree
        {
            return 0; 
        }

        if (prev != NULL && base_node->value <= prev->value) // comper value 
        {
            return 0;
        }
        prev = base_node;
        return is_binary_search_tree(base_node->right); // check for right tree
    }
    else
    {
        return 1;
    }
}

int main()
{
    node *root_node = make_node(5);
    node *node_1 = make_node(3);
    node *node_2 = make_node(6);
    node *node_3 = make_node(1);
    node *node_4 = make_node(4);

    //   tree
    /*       5
          /    \
         3      6
       /   \
       1    4
    */

    root_node->left = node_1;
    root_node->right = node_2;
    node_1->left = node_3;
    node_1->right = node_4;

    Inoder_traversal(root_node);
    printf(" \n");
    if (is_binary_search_tree(root_node))
    {
        printf("the binary tree is binary search tree  \n");
        
    }else{
        printf("the binary tree is not binary search tree  \n");
    }
    
    
    free(root_node);
    free(node_1);
    free(node_2);
    free(node_3);
    free(node_4);
    return 0;
}

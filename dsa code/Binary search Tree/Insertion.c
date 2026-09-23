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

node *search_Iterative(node *base_node, int value)
{ // Iterative Search
    while (base_node != NULL)
    {
        if (base_node == NULL)
        {
            return NULL;
        }
        if (base_node->value == value)
        {
            return base_node;
        }
        else if (base_node->value > value)
        {
            base_node = base_node->left;
        }
        else
        {
            base_node = base_node->right, value;
        }
    }
    return NULL;
}

void Insertion_BST(node *base_node, int value)
{ // Iterative Search
    node *prev = NULL;
    while (base_node != NULL)
    {
        prev = base_node;
        if (base_node == NULL)
        {
            return ;
        }
        if (base_node->value == value)
        {
            printf("%d alrady in binary search tree  \n", value);

            return ;
        }
        else if (base_node->value > value)
        {
            base_node = base_node->left;
        }
        else
        {
            base_node = base_node->right, value;
        }
    }
    // found right pointer to add value
    node *new_node = make_node(value);
    if (value < prev->value)
    {
        prev->left = new_node;
    }
    else
    {
        prev->right = new_node;
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

    Insertion_BST(root_node, 6);


     node *found = search_Iterative(root_node, 7);
    if (found != NULL)
    {
        printf(" element found in the binary search tree \n");
        printf("%d \n", found->value);
    }
    else
    {
        printf(" element not found in the binary search tree \n");
    }


    free(root_node);
    free(node_1);
    free(node_2);
    free(node_3);
    free(node_4);
    return 0;
}

// in preoder trsversal  - root->left -> right 

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
void preoder_traversal(node *base_node)
{ // recursive apprch help to solve fast binary tree

    if (base_node != NULL)
    {
        printf("%d ", base_node->value);
        preoder_traversal(base_node->left);
        preoder_traversal(base_node->right);
    }
}

int main()
{
    node *root_node = make_node(4);
    node *node_1 = make_node(1);
    node *node_2 = make_node(6);
    node *node_3 = make_node(5);
    node *node_4 = make_node(2);
    //   tree
    /*      4
          /    \
          1     6
        /   \
        5    2
    */

    root_node->left = node_1;
    root_node->right = node_2;
    node_1->left = node_3;
    node_1->right = node_4;

    preoder_traversal(root_node);
    free(root_node);
    free(node_1);
    free(node_2);
    free(node_3);
    free(node_4);
    return 0;
}

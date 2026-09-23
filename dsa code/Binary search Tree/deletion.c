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

node *in_oder_predecessor(node *root)
{

    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *search_BST(node *base_node, int value)
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
        return search_BST(base_node->left, value);
    }
    else
    {
        return search_BST(base_node->right, value);
    }
}

node *delete_BST(node *base_node, int value)
{ 
    node *ipre;
    if (base_node == NULL)
    {
        printf(" %d alrady not in binary search tree \n", value);
        return NULL;
    }
    if (base_node->left == NULL && base_node->right == NULL && base_node->value == value)
    {
        free(base_node);
        return NULL;
    }

    // finding deleting element

    if (value < base_node->value)
    {
        base_node->left = delete_BST(base_node->left, value);
    }
    else if (value > base_node->value)
    {
        base_node->right = delete_BST(base_node->right, value);
    }
    else
    {
        ipre = in_oder_predecessor(base_node);
        base_node->value = ipre->value;
        base_node->left = delete_BST(base_node->left, ipre->value);
    }

    return base_node;
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

int main()
{

    node *root_node = make_node(5);
    node *node_1 = make_node(3);
    node *node_2 = make_node(6);
    node *node_3 = make_node(1);
    node *node_4 = make_node(4);
    node *node_5 = make_node(10);

    //   tree
    /*       5
          /    \
         3      6
       /   \      \
       1    4      10
    */

    root_node->left = node_1;
    root_node->right = node_2;
    node_2->right = node_5 ;
    node_1->left = node_3;
    node_1->right = node_4;

    Inoder_traversal(root_node);
    printf(" \n");

    delete_BST(root_node, 10);
    printf(" \n");

    Inoder_traversal(root_node);
    free(root_node);
    free(node_1);
    free(node_2);
    free(node_3);
    free(node_4);
    return 0;
}

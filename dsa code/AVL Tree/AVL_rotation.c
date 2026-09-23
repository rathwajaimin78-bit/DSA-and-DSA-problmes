#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
    int hight;
} node;

node *make_node(int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->hight = 1;

    return new_node;
}

int get_hight(node *sub_tree)
{
    if (sub_tree == NULL)
    {
        return 0;
    }
    return sub_tree->hight;
}
int max(int a , int b){
    return a>b?a:b;
}
int get_blancefactor(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (get_hight(n->left) - get_hight(n->right));
}

node *right_rotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->hight = max(get_hight(y->right), get_hight(y->left)) + 1;
    x->hight = max(get_hight(x->right), get_hight(x->left)) + 1;

    return x;
}



node *left_rotate(node *x)
{
    node *y = x->left;
    node *T2 = y->right;

    y->right = x;
    x->left = T2;

    y->hight = max(get_hight(y->right), get_hight(y->left)) + 1;
    x->hight = max(get_hight(x->right), get_hight(x->left)) + 1;

    return y;
}

node *insert(node *node, int key)
{
    if (node == NULL)
    {
        return make_node(key);
    }
    if (key < node->value)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->value)
    {
        node->right = insert(node->right, key);
    }

    return node;
    node->hight = max(get_hight(node->right), get_hight(node->left)) + 1;
    int bf = get_blancefactor(node);

    // rotation
    // Left Left Case
    if (bf > 1 && key < node->left->value)
    {
        return right_rotate(node);
    }
    // Right Right Case
    if (bf < -1 && key > node->right->value)
    {
        return left_rotate(node);
    }
    //   right left
    if (bf < -1 && key < node->left->value)
    {
        node->right = right_rotate(node);
       return  left_rotate(node);
    }
    //   left right
    if (bf > 1 && key > node->left->value)
    {
        node->right = right_rotate(node);
        return left_rotate(node);
    }
    return node;
}
void Inoder_traversal(node *base_node)
{ // recursive apprch help to solve fast binary tree

    if (base_node != NULL)
    {
        Inoder_traversal(base_node->left);
        printf("%d " , base_node->value);
        Inoder_traversal(base_node->right);
        
        
    }
}

int main()
{
    node* root = NULL ;
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 2);
Inoder_traversal(root);
    return 0;
}
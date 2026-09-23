/*Doubly Linked Lists forward and backward flow*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    struct node *previous;
    struct node *next; // self referncing structure
} node;

void linked_list_traversal(node *start_point, node *last)
{
    int i = 1;
    node *x;
    while (start_point != NULL)
    {
        // forward
        printf("index %d : %d \n", i, start_point->value);
        start_point = start_point->next;
        i++;
    }
    printf(" \n");
    // backward
    while (last != NULL)
    {
        printf("index %d : %d \n", i, last->value);
        last = last->previous;
        i--;
    }
}
// insertion in liked nodes
void linked_list_insalltion(node *start_point)
{
    int i = 1;
    while (start_point != NULL)
    {
        printf("index %d :  \n", i);
        scanf("%d", &start_point->value);
        start_point = start_point->next;
        i++;
    }
}

int main()
{
    node *tharde;
    node *fist;
    node *secand;
    node *last;

    fist = (node *)malloc(sizeof(node));
    secand = (node *)malloc(sizeof(node));
    tharde = (node *)malloc(sizeof(node));
    last = (node *)malloc(sizeof(node));

    // forward
    fist->next = secand;
    secand->next = tharde;
    tharde->next = last;
    last->next = NULL;

    // backward
    fist->previous = NULL;
    secand->previous = fist;
    tharde->previous = secand;
    last->previous = tharde;

    linked_list_insalltion(fist);
    linked_list_traversal(fist, last);

    free(tharde);
    free(fist);
    free(last);
    free(secand);
    return 0;
}
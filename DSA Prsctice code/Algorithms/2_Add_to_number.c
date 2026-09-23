/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int value;
    struct node *next; // self referncing structure
} node;

void linked_list_traversal(node *start_point)
{
    int i = 1;
    node *x = start_point;

    do
    {
        printf("index %d : %d \n", i, start_point->value);
        start_point = start_point->next;
        i++;
    } while (start_point != x);
}
// insertion in liked nodes
void linked_list_insalltion(node *start_point)
{
    printf("this insalltion for list \n");

    int i = 1;
    node *x = start_point;
    do
    {
        printf("index %d :  ", i);
        scanf("%d", &start_point->value);
        start_point = start_point->next;
        i++;
    } while (start_point != NULL);
    printf(" \n");
}

void linked_list_deletion(node *starting_point)
{
    int index;
    int i = 1;
    node *p = starting_point;
    node *garbag;

    printf("enter node index to delete : \n");
    scanf("%d", &index);

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    garbag = p->next;
    p->next = (p->next)->next;

    free(garbag);
}

void linked_list_value_deletion(node *starting_point)
{
    int value;
    int index = 1;
    int i = 1;
    node *p = starting_point;
    node *p2 = starting_point;
    node *x = starting_point;
    node *garbag;

    printf("enter value to delete : \n");
    scanf("%d", &value);
    int found = 0;
    do
    {
        if (p->value == value)
        {
            found = 1;
            break;
        }
        p = p->next;

        index++;
    } while (p != x);

    if (!found) // found is 1 then ! convert 0 and if is fales ,  found is 0 then ! convert 1 and if is true
    {
        printf("element not found ! \n");
        return;
    }

    do
    {
        p2 = p2->next;
        i++;
    } while (i != index - 1);

    garbag = p2->next;
    p2->next = (p2->next)->next;

    free(garbag);
}

int revars_number_form_list(node *hade_node)
{

    int multiepal = 1;
    int revars_number = 0;
    int n = 0;
    while (hade_node != NULL)
    {
        revars_number = (hade_node->value) * multiepal + revars_number;
        multiepal *= 10;
        hade_node = hade_node->next;
        n++;
    }

    return revars_number;
}

int power(int base, int exp)
{
    int i = 0;
    int power = 1;

    for (int i = 0; i < exp; i++)
    {
        power *= base;
    }

    return power;
}

int max_power(int num)
{
    int base = 10;
    int multiple = 1;

    int power = 0;

    while (num / multiple)
    {
        power++;
        multiple *= base;
    }

    return power - 1;
}

int revars_number(int number){ // ....[(number/1000)%10] + [(number/100)%10]X10  + [(number/10)%10]X100 + [(number/1)%10]X1000
    //                                      (number/10^i)%10
    int revars_number = 0;

    int exp = max_power(number);
    int num = -1;
    int i = 0;
    while (num != 0)
    {
        num = (number / power(10, i));
        revars_number = revars_number + (num % 10) * (power(10, exp - i));

        i++;
    }
    return revars_number;
}

int main()
{
    node *L1_fist;
    node *L1_secand;
    node *L1_tharde;
    node *L1_last;

    node *L2_fist;
    node *L2_secand;
    node *L2_tharde;
    node *L2_last;

    L1_fist = (node *)malloc(sizeof(node));
    L1_secand = (node *)malloc(sizeof(node));
    L1_tharde = (node *)malloc(sizeof(node));
    L1_last = (node *)malloc(sizeof(node));

    L2_fist = (node *)malloc(sizeof(node));
    L2_secand = (node *)malloc(sizeof(node));
    L2_tharde = (node *)malloc(sizeof(node));
    L2_last = (node *)malloc(sizeof(node));

    L1_fist->next = L1_secand;
    L1_secand->next = L1_tharde;
    L1_tharde->next = L1_last;
    L1_last->next = NULL;

    L2_fist->next = L2_secand;
    L2_secand->next = L2_tharde;
    L2_tharde->next = L2_last;
    L2_last->next = NULL;

    // value between 0 to 9
    linked_list_insalltion(L1_fist); // 1234

    linked_list_insalltion(L2_fist); // 1234

    // revarsion bout numbers
    int num_1 = revars_number_form_list(L1_fist);
    int num_2 = revars_number_form_list(L2_fist);

    // for fuction checking
    printf(" revesrs number : %d \n", num_1);
    printf(" revesrs number : %d \n", num_2);

    int sum = num_1 + num_2;

    printf(" sum : %d \n", sum);

    int revrs_sum = revars_number(sum);

    // final output
    printf("sum in revers : %d \n", revrs_sum); 

    free(L1_tharde);
    free(L1_fist);
    free(L1_last);
    free(L1_secand);
    free(L2_tharde);
    free(L2_fist);
    free(L2_last);
    free(L2_secand);
    return 0;
}
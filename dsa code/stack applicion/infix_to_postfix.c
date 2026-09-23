/*Infix:
 Here the operator comes in between two operands. And we say, two is added to three. For eg: a * b, 6 / 3 etc.
     2           +          3
< operand 1 >< operator >< operand2 >

Prefix:

we have vocally used them a lot as well. Here the operator comes before the two operands. And we say, Add two and three. For e.g.:  + 6 8, * x y, -  3 2 etc.
    add           2     and     3
< operator >< operand 1 >< operand2 >

Postfix:

we have used even this in our communication. Here the operator comes after the two operands. And we say, Two and three are added. For e.g.:  5 7 +, a  b *,  12 6 / etc.
    5       and    4        add it
< operand 1 >< operand2 >< operator >*/

// infix to  postfix convrteing programe

// all operation done in O(1) time complexity

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack // like a storage
{
    int size;
    int top;     // using top element index
    char *array; // dynimacliy memory first point address
} Stack;
// x-y/z-k*a = xyz/-ka*-
void empty_or_not(Stack *point)
{

    if (point->top == -1)
    {
        // printf("stack is empty ! \n");
    }
    else
    {
        // printf("stack is not empty ! \n");
    }
}

void full_or_not(Stack *point)
{

    if (point->top == point->size - 1)
    {
        // printf("stack is full ! \n");
    }
    else
    {
        // printf("stack is not full ! \n");
    }
}

int push(char value, Stack *name)
{

    if (name->top == name->size)
    {
        full_or_not(name);
        // printf("Stack overflow ! \n");
        return 0;
    }
    else
    {
        name->top = name->top + 1; // incresing index
        (name->array[name->top]) = value;
        // printf("successfully %c entered \n", value);
    }
}
int pop(Stack *name)
{ // not completed , update completed !

    if (name->top == -1) // checking stack
    {
        empty_or_not(name);
        return 0;
    }
    else
    {
        char delting_value = name->array[name->top];
        // printf("successfully removed %c  \n", name->array[name->top]);
        return name->top = name->top - 1; // decresing index
    }
}

int precedence(char check)
{
    if (check == '+' || check == '-')
    {
        return 1;
    }
    if (check == '/' || check == '*')
    {
        return 2;
    }
    return 0;
}

void infix_to_postfix(char expresion[], Stack *stroage)
{
    int j = 0;
    char postfix_expresion[30];
    for (int i = 0; i < strlen(expresion); i++)
    {
        if (precedence(expresion[i]) != 0)
        {

            if (precedence(expresion[i]) > precedence(stroage->array[stroage->top]))
            {
                push(expresion[i], stroage);
            }
            else if (precedence(expresion[i]) < precedence(stroage->array[stroage->top]))
            {

                postfix_expresion[j] = expresion[stroage->top];
                pop(stroage);
                j++;
            }
        }
        else
        {
            postfix_expresion[j] = expresion[i];
            // pop(stroage);
            j++;
        }
    }
    while (stroage->top != -1)
    {
        postfix_expresion[j++] = stroage->array[stroage->top];
        stroage->top--;
    }
    postfix_expresion[j] = '\0';

    printf("%s", postfix_expresion);
}
int main()
{
    Stack *storage = (Stack *)malloc(sizeof(Stack));
    storage->array = (char *)malloc(storage->size * sizeof(char));
    storage->top = -1;  // -1 show no elemnt remning(nothing any elment) after 0th elemnt
    char expresion[30]; // input
    printf("enter mathematcal equsion in infix  \n");
    scanf("%29s", &expresion);
    storage->size = strlen(expresion);
    infix_to_postfix(expresion, storage);

    free(storage->array);
    free(storage);
    return 0;
}
// incompled
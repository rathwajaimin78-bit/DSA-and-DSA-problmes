// palindrme string finding program 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int in_string_or_not(char string[], char c) // check give cheracter already in or not
{
    for (int i = 0; i < strlen(string); i++)
    {

        if (string[i] == c)
        {
            return 1; // true
        }
    }
    return 0; // flase
}
int find_index_in_string(char string[], char c) // find index I of repting index
{
    for (int i = 0; i < strlen(string); i++)
    {

        if (string[i] == c)
        {
            return i;
        }
    }
    return 0;
}

char *cut_string(char str[], int form, int to) // cut string between two given indexs
{

    int size = form - to + 2;
    char *palindromic = (char *)malloc(size * sizeof(char));
    if (palindromic == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    int j = 0;
    for (int i = form; i <= to; i++)
    {
        palindromic[j] = str[i];
        j++;
    }
    palindromic[j] = '\0'; // Null-terminate the string

    return palindromic;
}

int main()
{

    char string[30];

    printf("enter string : ");
    scanf("%s", string);

    int lenth = strlen(string);

    char sub_string[30];

    int in = 0;

    int J = 0;
    int I = 0;

    for (int i = 0; i < lenth; i++)
    {
        if (in_string_or_not(sub_string, string[i]))
        {
            J = i;
            break;
        }
        sub_string[in] = string[i];
        in++;
    }

    I = find_index_in_string(string, string[J]);
    // printf("%d to %d \n" , I , J);

    if ((I == 0 && J == lenth - 2) || J == 0)
    {
        printf("not any Palindromic Substring \n");
        return 0;
    }

    char *palindromic = cut_string(string, I, J);

    printf("%s \n", palindromic);

    free(palindromic);
    return 0;
}

// worst time complexity O(n)
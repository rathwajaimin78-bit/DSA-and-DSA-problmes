 // longest palindrme string finding program 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int in_string_or_not(char string[], char c) // check give cheracter already in or not
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == c)
        {
            return 1;
        }
    }
    return 0;
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
    int size = to - form + 2;
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

int is_palindrome(char str[], int start, int end) // check palindrme "absta"
{
    while (start < end)
    {
        if (str[start] != str[end]) // starting and ending index must be same for palindrme 
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main()
{
    char string[30];
    printf("Enter string: ");
    scanf("%s", string);

    int len = strlen(string);
    if (len <= 1) // if only null cher not  Palindromic
    {
        printf("Not any Palindromic Substring\n");
        return 0;
    }

    int longest_palindrome_len = 1;
    char *longest_palindrome = (char *)malloc(30 * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 2; j <= len; j++)
        { // Check substrings starting from length 2
            if (is_palindrome(string, i, j))
            {
                if (j - i > longest_palindrome_len)
                {
                    longest_palindrome_len = j - i;
                    strncpy(longest_palindrome, &string[i], j - i + 1);
                    longest_palindrome[j - i + 1] = '\0'; // Null-terminate the string
                }
            }
        }
    }

    if (longest_palindrome_len > 1)
    {
        printf("Longest Palindromic Substring: %s\n", longest_palindrome);
    }
    else
    {
        printf("Not any Palindromic Substring\n");
    }

    free(longest_palindrome);

    return 0;
}

// worst time complexity O(n^2)

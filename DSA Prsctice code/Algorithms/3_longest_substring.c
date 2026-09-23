/*  Given a string s, find the length of the longest substring without duplicate characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
    */

#include <stdio.h>
#include <string.h>

int in_string_or_not(char string[], char c)
{
    for (int i = 0; i < strlen(string); i++)
    {

        if (string[i] == c)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{

    char string[30];
    printf("enter string : ");
    scanf("%s", string);

    char sub_string[30];
    int j = 0;
    int k = 0;
    // wrtxssw
    for (int i = k; i < strlen(string); i++)
    {
        if (in_string_or_not(sub_string, string[i]))
        {
            sub_string[j] = string[i];
            j++;
            sub_string[j] = '\0';
        }
        else
        {
            j = 0;
            k++;
        }
    }

    printf("%s \n", sub_string);
    printf("%d \n" , strlen(sub_string));
    

    return 0;
}
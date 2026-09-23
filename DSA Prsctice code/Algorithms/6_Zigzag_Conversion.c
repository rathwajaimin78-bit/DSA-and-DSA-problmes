// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:

//  P      I      N     n-2 / and n-1 | -i
//  A   L/ S   I/ G
//  Y  A/  H  R/
//  P  /   I  /

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size = 25;
    char *s = (char *)malloc(size * sizeof(char));
    int number_of_Row = 3;

    printf("enter a word :  ");
    scanf("%s", &s);

    for (int i = 0; i < number_of_Row; i++)
    {
        printf("%c", s[i]);

        for (int j = i; j < 1; j = j + (number_of_Row - 2 + number_of_Row - 1) - 2*i)
        {
            printf("%c", s[j +1]);
        }
    }

    free(s);
    return 0;
}
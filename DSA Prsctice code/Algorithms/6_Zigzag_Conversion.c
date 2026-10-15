// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:

//  P      I      N     n-2 / and n-1 | -i
//  A   L/ S   I/ G
//  Y  A/  H  R/
//  P  /   I  /



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len) {
        return s;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int index = 0;
    int cycle = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {
        for (int j = row; j < len; j += cycle) {
            result[index++] = s[j];

            int diagonal = j + cycle - 2 * row;

            if (row != 0 && row != numRows - 1 &&
                diagonal < len) {
                result[index++] = s[diagonal];
            }
        }
    }

    result[index] = '\0';
    return result;
}

int main() {
    char s[] = "PAYPALISHIRING";
    int numRows = 3;

    char* result = convert(s, numRows);

    if (result != NULL) {
        printf("%s\n", result);

        if (result != s) {
            free(result);
        }
    }

    return 0;
}

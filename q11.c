/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/

#include <stdio.h>

int main() {
    char s[1000];
    int i = 0;

    // Read input string (no spaces)
    scanf("%s", s);

    // Find length manually
    while (s[i] != '\0') {
        i++;
    }

    // Print in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", s[j]);
    }

    return 0;
}

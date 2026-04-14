/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/

#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

char firstNonRepeating(char *s) {
    int count[MAX_CHARS] = {0};
    int len = strlen(s);
    
    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        count[s[i]]++;
    }
    
    // Find first character with count = 1
    for (int i = 0; i < len; i++) {
        if (count[s[i]] == 1) {
            return s[i];
        }
    }
    
    // No non-repeating character found
    return '$';
}

int main() {
    char s[1001];
    
    // Read input string
    scanf("%s", s);
    
    // Find and print result
    char result = firstNonRepeating(s);
    printf("%c\n", result);
    
    return 0;
}
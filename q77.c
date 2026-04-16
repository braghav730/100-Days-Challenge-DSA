/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple hash map using arrays
typedef struct {
    int key;
    int value;
} Hash;

Hash hash[MAX];
int size = 0;

// Function to find key in hash
int find(int key) {
    for (int i = 0; i < size; i++) {
        if (hash[i].key == key)
            return i;
    }
    return -1;
}

// Insert into hash
void insert(int key, int value) {
    hash[size].key = key;
    hash[size].value = value;
    size++;
}

int maxLen(int arr[], int n) {
    int sum = 0, maxLength = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0
        if (sum == 0) {
            maxLength = i + 1;
        }

        int idx = find(sum);

        // Case 2: sum seen before
        if (idx != -1) {
            int length = i - hash[idx].value;
            if (length > maxLength)
                maxLength = length;
        } else {
            insert(sum, i); // store first occurrence
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));
    return 0;
}
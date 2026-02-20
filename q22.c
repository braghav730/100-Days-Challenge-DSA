/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/

#include <stdio.h>

int main() {
    int n;
    
    // Read number of elements
    scanf("%d", &n);

    int arr[n];
    
    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // Frequency array to store count of prefix sums
    // Range assumed from -10000 to +10000
    int freq[20001] = {0};

    // To handle subarrays starting from index 0
    freq[10000] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If prefix sum already exists, add its frequency to count
        count += freq[prefixSum + 10000];

        // Increase frequency of current prefix sum
        freq[prefixSum + 10000]++;
    }

    // Print the result
    printf("%d", count);

    return 0;
}
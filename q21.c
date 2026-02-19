/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int minSum = 100000; 
    int a = 0, b = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if (sum < 0)
                sum = -sum;

            if (sum < minSum)
            {
                minSum = sum;
                a = arr[i];
                b = arr[j];
            }
        }
    }

    printf("%d %d\n", a, b);

    return 0;
}

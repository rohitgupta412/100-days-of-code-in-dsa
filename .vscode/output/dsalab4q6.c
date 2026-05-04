// 6.	C Program to Find the Largest Sum of Contiguous Subarray of an Array.
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (current_sum + arr[i] > arr[i])
            current_sum = current_sum + arr[i];
        else
            current_sum = arr[i];

        if (current_sum > max_sum)
            max_sum = current_sum;
    }

    printf("%d", max_sum);

    return 0;
}
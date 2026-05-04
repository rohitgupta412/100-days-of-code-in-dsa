//2.	Write a C program to find the sum of the main diagonal elements of a matrix
#include <stdio.h>

int main()
{
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("enter element for arr[%d][%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += arr[i][i];
    }
    printf("sum of main diagonal : %d ", sum);

    return 0;
}
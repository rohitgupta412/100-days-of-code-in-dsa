//3.	Write a C program to check the Identity matrix.
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

    int flag = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i == j && arr[i][j] != 1) || (i != j && arr[i][j] != 0))
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag)
    {
        printf("Identity matrix");
    }
    else
    {
        printf("Not an Identity matrix");
    }

    return 0;
}
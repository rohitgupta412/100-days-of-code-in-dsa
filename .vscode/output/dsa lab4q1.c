// 1.	Find the second largest element in an array.
#include <stdio.h>

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    int li = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > arr[li])
        {
            li = i;
        }
    }
    int temp = arr[0];
    arr[0] = arr[li];
    arr[li] = temp;

    int sl = arr[1];
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] > sl)
        {
            sl = arr[i];
        }
    }
    printf("second largest : %d ", sl);

    return 0;
}
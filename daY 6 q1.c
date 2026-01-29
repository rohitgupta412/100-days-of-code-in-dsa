/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)*/
#include<stdio.h>

int main()
{
    int n,i,j;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d sorted integers: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unique elements in the array are: ");
    for(i=0;i<n;i++)
    {
        if(i==0 || arr[i] != arr[i-1])
        {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}
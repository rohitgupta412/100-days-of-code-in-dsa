/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int isPalindrome(char str[])
{
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}
int main()
{
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
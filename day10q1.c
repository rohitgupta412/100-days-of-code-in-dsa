#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left = 0, right;

    // Read input string
    scanf("%s", s);

    // Set right pointer to last character
    right = strlen(s) - 1;

    // Two-pointer comparison
    while (left < right) {
        if (s[left] != s[right]) {
            printf("NO");
            return 0;
        }
        left++;
        right--;
    }

    // If all characters matched
    printf("YES");
    return 0;
}

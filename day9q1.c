#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    // Read input string
    scanf("%s", str);

    len = strlen(str);

    // Print characters in reverse order
    for (i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}

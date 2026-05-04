#include <stdio.h>

int power(int a, int b) {
    // Base case
    if (b == 0)
        return 1;
    else
        return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Input
    scanf("%d %d", &a, &b);

    // Output
    printf("%d", power(a, b));

    return 0;
}

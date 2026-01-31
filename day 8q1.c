#include <stdio.h>

// Recursive function to calculate power
int power(int a, int b) {
    if (b == 0)
        return 1;              // Base case
    else
        return a * power(a, b - 1);  // Recursive case
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);    // Input a and b
    printf("%d", power(a, b));
    return 0;
}

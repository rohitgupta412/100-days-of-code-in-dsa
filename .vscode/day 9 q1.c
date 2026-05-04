/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)*/
#include <stdio.h>
#include <string.h>
void mirrorCodeName(char codeName[]) {
    int length = strlen(codeName);
    char mirror[length + 1]; // +1 for null terminator

    // Reverse the string
    for (int i = 0; i < length; i++) {
        mirror[i] = codeName[length - 1 - i];
    }
    mirror[length] = '\0'; // Null terminate the string

    printf("Mirror Code Name: %s\n", mirror);
}
int main() {
    char codeName[100]; // Assuming the code name won't exceed 99 characters

    printf("Enter the code name: ");
    scanf("%s", codeName);

    mirrorCodeName(codeName);

    return 0;
}
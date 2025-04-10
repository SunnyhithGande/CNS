#include <stdio.h>

int main() {
    char str[] = "Hello World";
    int i;

    printf("Original\tAND\tOR\tXOR\n");
    printf("Char\tASCII\t127\t127\t127\n");
    printf("-----\t-----\t---\t---\t---\n");

    for (i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        printf("%c\t%d\t%d\t%d\t%d\n", ch, ch, ch & 127, ch | 127, ch ^ 127);
    }

    return 0;
}

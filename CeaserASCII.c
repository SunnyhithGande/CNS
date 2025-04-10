#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    int key, i;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key (shift): ");
    scanf("%d", &key);

    printf("\nOriginal -> ASCII -> Encrypted -> ASCII\n");
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char encrypted = ((ch - base + key) % 26) + base;

            printf("   %c      ->  %3d   ->     %c     ->  %3d\n", ch, ch, encrypted, encrypted);
        } else {
            // If not an alphabet, keep it unchanged
            printf("   %c      ->  %3d   ->     %c     ->  %3d\n", ch, ch, ch, ch);
        }
    }

    return 0;
}

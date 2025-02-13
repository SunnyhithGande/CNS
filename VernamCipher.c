#include <stdio.h>
#include <string.h>
void vernamCipher(char *text, char *key) 
{
    int i;
    int length = strlen(text);
    for (i = 0; i < length; i++) 
    {
        text[i] = text[i] ^ key[i];
    }
}

int main() 
{
    char plaintext[100], key[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    size_t length = strlen(plaintext);
    if (plaintext[length - 1] == '\n') 
    {
        plaintext[length - 1] = '\0';
    }

    printf("Enter the key (must be of the same length as plaintext): ");
    fgets(key, sizeof(key), stdin);
    length = strlen(key);
    if (key[length - 1] == '\n') 
    {
        key[length - 1] = '\0';
    }
    if (strlen(plaintext) != strlen(key)) 
    {
        printf("Error: Key must be the same length as the plaintext.\n");
        return 1;
    }
    printf("\nEncrypting...\n");
    vernamCipher(plaintext, key);
    printf("Ciphertext: %s\n", plaintext);
    vernamCipher(plaintext, key);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}


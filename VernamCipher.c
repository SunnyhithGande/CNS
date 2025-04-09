#include <stdio.h>
#include <string.h>

int main()
{
    char pstr[100];
    char key[100];

    printf("Enter plaintext: ");
    scanf("%s", pstr);
    printf("Enter key: ");
    scanf("%s", key);

    int i;
    int len = strlen(pstr);

    if (len == strlen(key))
    {
        // Encrypt
        for (i = 0; i < len; i++)
        {
            pstr[i] = pstr[i] ^ key[i];
        }

        printf("Encrypted: ");
        for (i = 0; i < len; i++)
            printf("%02X ", (unsigned char)pstr[i]);  // Display in hex
        printf("\n");

        // Decrypt
        for (i = 0; i < len; i++)
        {
            pstr[i] = pstr[i] ^ key[i];
        }

        printf("Decrypted: %s\n", pstr);
    }
    else
    {
        printf("Key and plaintext must be the same length.\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() 
{
    char plainText[20], key[20];
    printf("Enter PlainText: ");
    scanf("%s", plainText);
    printf("Enter Key: ");
    scanf("%s", key);
    int ps = strlen(plainText);
    int ks = strlen(key);
    int i, j = 0;
    for(i = 0; plainText[i] != '\0'; i++) 
    {
        plainText[i] = ((plainText[i] - 'A' + key[j % ks] - 'A') % 26) + 'A';
        j++;
    }
    printf("Encrypted Text: %s\n", plainText);

    j = 0;
    for(i = 0; plainText[i] != '\0'; i++) 
	{
        plainText[i] = ((plainText[i] - 'A' - (key[j % ks] - 'A') + 26) % 26) + 'A';
        j++;
    }
    printf("Decrypted Text: %s\n", plainText);
    return 0;
}

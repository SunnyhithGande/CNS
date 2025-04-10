#include <stdio.h>
#include <ctype.h>

int main()
{
    char pstr[100];
    scanf("%s", pstr);
    
    int key;
    scanf("%d", &key);
    
    int i;
    // Encrypt
    for(i = 0; pstr[i] != '\0'; i++)
    {
        char ch = pstr[i];
        if(isupper(ch)) // only apply to uppercase letters
        {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        pstr[i] = ch;
    }
    printf("Encrypted: %s\n", pstr);

    // Decrypt
    for(i = 0; pstr[i] != '\0'; i++)
    {
        char ch = pstr[i];
        if(isupper(ch))
        {
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        }
        pstr[i] = ch;
    }
    printf("Decrypted: %s\n", pstr);
    return 0;
}

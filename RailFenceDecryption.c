#include <stdio.h>
#include <string.h>
int main() 
{
    char plainText[20];
    int cipher[20][20];
    char cipherText[20];
    int depth;
    
    printf("Enter PlainText: ");
    scanf("%s", plainText);
    
    printf("Enter Depth: ");
    scanf("%d", &depth);
    
    int i, j = 0;
    int flag = 0;
    
    for(i = 0; i < depth; i++) 
	{
        for(j = 0; j < strlen(plainText); j++) 
		{
            cipher[i][j] = 0;
        }
    }

    j = 0;
    for(i = 0; i < strlen(plainText); i++) 
	{
        cipher[j][i] = (int)plainText[i];
        
        if(j == 0) 
		{
            flag = 0;
        } else if(j == depth - 1) 
		{
            flag = 1;
        }

        if(flag == 1) 
		{
            j--;
        } else 
		{
            j++;
        }
    }

    printf("Encrypted Text: ");
    for(i = 0; i < depth; i++) 
	{
        for(j = 0; j < strlen(plainText); j++) 
		{
            if(cipher[i][j] != 0) 
			{
                printf("%c", cipher[i][j]);
            }
        }
    }
    printf("\n");

    printf("Decrypted Text: ");
    char decryptedText[strlen(plainText)];
    i = 0, j = 0;
    flag = 0;

    for(i = 0; i < strlen(plainText); i++) 
	{
        decryptedText[i] = (char)cipher[j][i];
        
        if(j == 0) 
		{
            flag = 0;
        } else if(j == depth - 1) 
		{
            flag = 1;
        }

        if(flag == 1) 
		{
            j--;
        } else 
		{
            j++;
        }
    }
    
    decryptedText[strlen(plainText)] = '\0';
    printf("%s\n", decryptedText);
    
    return 0;
}


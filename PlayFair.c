#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

void toUpperCase(char encrypt[], int ps);
int removeSpaces(char* plain, int ps);
void generateKeyTable(char keystr[], int ks, char keyT[5][5]);
int prepare(char str[], int ptrs);
void search(char keyT[5][5], char a, char b, int arr[]);
void encrypt(char str[], char keyT[5][5], int ps);
void PlayFairCrypt(char str[], char keystr[]);

int main()
{
    char str[SIZE], keystr[SIZE];
    printf("Enter the key: ");
    scanf("%s", keystr);
    printf("Key text: %s\n", keystr);
    
    printf("Enter the plaintext: ");
    scanf("%s", str);
    printf("Plain text: %s\n", str);
    
    PlayFairCrypt(str, keystr);
    
    return 0;
}

void toUpperCase(char encrypt[], int ps)
{
    int i;
    for(i = 0; i < ps; i++)
    {
        if(encrypt[i] >= 'a' && encrypt[i] <= 'z')
        {
            encrypt[i] -= 32;
        }
    }
}

int removeSpaces(char* plain, int ps)
{
    int i, count = 0;
    for(i = 0; i < ps; i++)
    {
        if(plain[i] != ' ')
        {
            plain[count++] = plain[i];
        }
    }
    plain[count] = '\0';
    return count;
}

void generateKeyTable(char keystr[], int ks, char keyT[5][5])
{
    int i, j, k;
    int dicty[26] = {0};
    
    for(i = 0; i < ks; i++)
    {
        if(keystr[i] != 'j')
        {
            dicty[keystr[i] - 'a'] = 2;
        }
    }
    dicty['j' - 'a'] = 1;
    
    i = 0;
    j = 0;
    for(k = 0; k < ks; k++)
    {
        if(dicty[keystr[k] - 'a'] == 2)
        {
            dicty[keystr[k] - 'a'] = 1;
            keyT[i][j] = keystr[k];
            j++;
            if(j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    
    for(k = 0; k < 26; k++)
    {
        if(dicty[k] == 0)
        {
            keyT[i][j] = (char)(k + 'a');
            j++;
            if(j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
}

int prepare(char str[], int ptrs)
{
    int i, j, subs_s = ptrs;
    
    for(i = 0; i < subs_s; i += 2)
    {
        if(str[i] == str[i+1])
        {
            for(j = subs_s; j > i + 1; j--)
            {
                str[j] = str[j-1];
            }
            str[i + 1] = 'x';
            subs_s += 1;
        }
    }
    str[subs_s] = '\0';
    
    if(subs_s % 2 != 0)
    {
        str[subs_s++] = 'x';
        str[subs_s] = '\0';
    }
    return subs_s;
}

void search(char keyT[5][5], char a, char b, int arr[])
{
    int i, j;
    if(a == 'j') a = 'i';
    if(b == 'j') b = 'i';
    
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(keyT[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            if(keyT[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

void encrypt(char str[], char keyT[5][5], int ps)
{
    int i, a[4];
    for(i = 0; i < ps; i += 2)
    {
        search(keyT, str[i], str[i+1], a);
        
        if(a[0] == a[2])
        {
            str[i] = keyT[a[0]][(a[1]+1) % 5];
            str[i+1] = keyT[a[0]][(a[3]+1) % 5];
        }
        else if(a[1] == a[3])
        {
            str[i] = keyT[(a[0]+1) % 5][a[1]];
            str[i+1] = keyT[(a[2]+1) % 5][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i+1] = keyT[a[2]][a[1]];
        }
    }
}

void PlayFairCrypt(char str[], char keystr[])
{
    char keyT[5][5];
    int ks = strlen(keystr);
    int ps = strlen(str);
    
    ks = removeSpaces(keystr, ks);
    ps = removeSpaces(str, ps);
    ps = prepare(str, ps);
    
    generateKeyTable(keystr, ks, keyT);
    encrypt(str, keyT, ps);
    toUpperCase(str, ps);
    
    printf("CipherText: %s\n", str);
}


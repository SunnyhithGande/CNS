#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	printf("Enter PT : ");
	scanf("%s",str);
	int depth;
	printf("Enter depth: ");
	scanf("%d",&depth);
	int len = strlen(str);
	int fence[depth][len];
	int i,j,k;
	for(i=0; i<depth; i++)
	{
		for(j=0; j<strlen(str); j++)
		{
			fence[i][j] = 0;
		}
	}
	i=0;
	j=0;
	int flag;
	for(j=0; j<strlen(str); j++)
	{
		fence[i][j] = str[j];
		if(i==0)
		{
			flag = 0;
		}
		else if(i==depth-1)
		{
			flag=1;
		}
		
		if(flag == 0)
		{
			i++;
		}
		else
		{
			i--;
		}
	}
	char cipher[100];
	k=0;
	for(i=0; i<depth; i++)
	{
		for(j=0; j<strlen(str); j++)
		{
			if(fence[i][j] != 0)
			{
				cipher[k] = (char)fence[i][j];
				k++;
			}
		}
	}
	
	printf("The cipher Text is :%s",cipher);
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char followresult[10];
void first(char c);
void follow(char c);
char a[20][20];
void addtoresult(char);
int n,m=0;
int main()
{
	char c,ch;	
	int choice;
	printf("enter no of productions:");
	scanf("%d",&n);
	printf("enter the productions:");
	for(int i=0;i<n;i++)
	scanf("%s%c",a[i],&ch);
	do
	{
	m=0;
		printf("enter the follow of :");
		scanf(" %c",&c);
		follow(c);
		printf("follow(%c)={ ",c);
		for(int i=0;i<m;i++)
		{
			printf("%c ",followresult[i]);
		}
		printf(" }\n");
		printf("enter 1 to continue:");
		scanf("%d%c",&choice,&ch);
	}
	while(choice==1);
}
void follow(char c)
{
	if(a[0][0]==c)
	addtoresult('$');
	for(int i=0;i<n;i++)
	{
		for(int j=2;j<strlen(a[i]);j++)
		{
			if(a[i][j]==c)
			{
				if(a[i][j+1]!='\0')
				first(a[i][j+1]);
				if(a[i][j+1]=='\0' && c!=a[i][0])
				follow(a[i][0]);
			}
		}
	}
}
void first(char c)
{
int i;
	if(!(isupper(c)))
	addtoresult(c);
	//return;}
	for( i=0;i<n;i++)
	{
		if(a[i][0]==c)
		{
			if(a[i][2]=='$')
			follow(a[i][0]);
			else if(islower(a[i][2]))
			addtoresult(a[i][2]);
			else
			first(a[i][2]);
		}
	}
}
void addtoresult(char c)
{
	int i;
	for(i=0;i<=m;i++){
		if(followresult[i]==c)
		return;}
		//followresult[i]=c;
		followresult[m++]=c;
}

	

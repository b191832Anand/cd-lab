#include<stdio.h>
#include<ctype.h>
int n;
void first(char[],char);
void addtoresult(char[],char);
char productionset[50][50];

int main()
{
	char result[20];
	int choice;
	char c;
	printf("enter n:");
	scanf(" %d",&n);
	printf("enter the productions:");
	for(int i=0;i<n;i++)
	scanf(" %s",productionset[i]);
	
	do
	{
		printf("enter the first :");
		scanf(" %c",&c);
	//	scanf(" %c",&c);
		first(result,c);
		printf("first(%c) = { ",c);
		for(int i=0;result[i]!='\0';i++)
		printf(" %c",result[i]);
		printf("}\n");
		printf("enter 1 to continue:");
		scanf(" %d",&choice);
	//	scanf(" %d",&choice);
	}
	while(choice==1);
}
void first(char *result,char c)
{
	char subresult[20];
	int flag,j;
	subresult[0]='\0';
	result[0]='\0';
	if(!(isupper(c))){
	addtoresult(result,c);
	return;}
	for(int i=0;i<n;i++)
	{
		if(productionset[i][0]==c)
		{
			if(productionset[i][2]=='$')
			addtoresult(result,'$');
			else
			{
				 j=2;
				while(productionset[i][j]!='\0')
				{
					flag=0;
					first(subresult,productionset[i][j]);
					for(int i=0;subresult[i]!='\0';i++)
					addtoresult(result,subresult[i]);
					for(int i=0;subresult[i]!='\0';i++)
						if(subresult[i]=='$'){
						flag=1;
						break;}
	
					if(!flag)
						
						break;
						j++;
				}
			}
		}
	}
	return;
}
void addtoresult(char *result,char c)
{
	int i;
	for(i=0;result[i]!='\0';i++)
		if(result[i]==c)
		return;
		result[i]=c;
		result[i+1]='\0';
}
					
		
	

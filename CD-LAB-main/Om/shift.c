#include<stdio.h>
#include<string.h>
struct product
{
	char left[10];
	char right[10];
};
int main(){
char stack[50],temp[20],ch[2],input[10],*token1,*token2,*substring;
int i,j,k,n,stacklength,substringlength,stacktop;
struct product rule[10];
stack[0]='\0';
printf("enter n:");
scanf("%d",&n);
printf("enter productions:");
for(i=0;i<n;i++)
{
	scanf("%s", temp);
	token1=strtok(temp, "->");
	token2=strtok(NULL, "->");
	strcpy(rule[i].left,token1);
	strcpy(rule[i].right,token2);
}
printf("enter input:");
scanf("%s", input);

i=0;
while(1)
{
	if(i<strlen(input))
	{
		ch[0]=input[i];
		ch[1]='\0';
		i++;
		strcat(stack,ch);
		printf("%s\t",stack);
		for(k=i;k<strlen(input);k++)
		{
			printf("%c",input[k]);
		}
		printf("\tshift %s\n",ch);
	}
	for(j=0;j<n;j++)
	{
	substring=strstr(stack,rule[j].right);
	if(substring!=NULL)
	{
		stacklength=strlen(stack);
		substringlength=strlen(substring);
		stacktop=stacklength-substringlength;
		stack[stacktop]='\0';
		strcat(stack,rule[j].left);
		printf("%s\t",stack);
		for(k=i;k<strlen(input);k++)
		{
			printf("%c",input[k]);
		}
		printf("\treduce %s->%s\n",rule[j].left,rule[j].right);
		j=-1;
	}
	}
	if(strcmp(stack,rule[0].left)==0 && i==strlen(input))
	{
		printf("accepted");
		break;
	}
	if(i==strlen(input))
	{
		printf("rejected");
		break;
	}
}
return 0;
}		
		
		
	


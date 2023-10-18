#include<stdio.h>

int main(void)
{

	int age;
	char name[21];
	printf("Insira o nome e a idade:");
	scanf("%s%d",&name,&age);
	printf("%s%s%s%d%s","\nHello ",name,", next year you will be ",age+1,"\n");
	return 0;

}

/*************************************************************************
    > File Name: strrch.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月28日 星期四 10时56分50秒
 ************************************************************************/

#include <stdio.h>
//#include <conio.h>
#include <string.h>
int main(void)
{
	char string[20];
	char *ptr;
	char c='r';
	strcpy(string,"There are two rings");
	ptr=strrchr(string,c);
	//ptr=strchr(string,c);
	if (ptr!=NULL)
	{
		printf("The character %c is at position:%s\n",c,ptr);
	}
	else
	{
		printf("The character was not found\n");
	}
	//getch();
	return 0;
}


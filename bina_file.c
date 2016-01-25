/*************************************************************************
    > File Name: bina_file.c
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月08日 星期五 18时40分33秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<setjmp.h>
jmp_buf jmp;
int main()
{
	int n;
	char buf[1024];
	int fd;
	if((fd=open("./bian_file.txt",O_RDWR|O_CREAT|O_TRUNC))<0)
	{
		printf("open error\n");
		exit(0);
	}
	//if(setjmp(jmp)!=0)
	{
//		printf("error\n");
	//	exit(0);
	}
	pid_t id;
	if((id=fork())==0)
	{
		printf("parent\n");
	}
	else if(id>0)
	{
		printf("child\n");
	}
	else
	{
		printf("error\n");
	}
	extern char **environ;
	char **ptr;
	for(ptr=environ;*ptr!=0;ptr++)
	{
		printf("%s\n",*ptr);
	}
	//while((n=read(STDIN_FILENO,buf,1024))>0)
	{
	//	if(write(fd,buf,n)==n)
		{
	//		printf("write error\n");
	//		longjmp(jmp,1);
		}
	}
	exit(0);
}

/*************************************************************************
    > File Name: signal.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月14日 星期四 15时17分32秒
 ************************************************************************/
#include<iostream>
#include<pwd.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/signal.h>
#include<setjmp.h>
using namespace std;
jmp_buf env;
//父子进程信号处理
static void sig_alarm(int signo)
{
    printf("start..env.\n");
    alarm(1);
    longjmp(env,1);
}

int main(int argc, char** argv)
{
    int n;
    char line[10000];
    unsigned int unsleep;
    if(signal(SIGALRM,sig_alarm)==SIG_ERR)
    {
        perror("SIGALRM error\n"); 
    }
	printf("start...\n");
    if(setjmp(env)==0)
    {
        perror("setjmp error\n"); 
    }
	printf("start...\n");
    alarm(2);
    if((n=read(STDIN_FILENO,line,10000))<0)
        perror("STDIN_FILENO error\n"); 
    alarm(0);
	int a;
	a = (a=1,2);
	printf("%d",a);
    write(STDOUT_FILENO,line,n);
    exit(0);
}

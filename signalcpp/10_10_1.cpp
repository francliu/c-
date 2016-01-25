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
    longjmp(env,1);
}
unsigned int sleep2(unsigned int sec)
{
    if(signal(SIGALRM,sig_alarm)==SIG_ERR)
    {
        return sec;
    }
    if(setjmp(env)==0)
    {
        alarm(sec);
        pause();
    }
    return alarm(0);
}
static void sig_int(int signo)
{
   int i,j;
   volatile int k;
   printf("start...\n");
   for(i=0;i<30000;i++)
   {
       for(j=0;j<4000;j++)
       {
           k+=i*j;
       }
   }
   printf("sig_int finished\n");
   //printf("pid=%d\n",pid);
}

int main(int argc, char** argv)
{
    unsigned int unsleep;
    if(signal(SIGINT,sig_int)==SIG_ERR)
    {
        perror("error\n"); 
    }
    unsleep=sleep2(5);
    printf("sleep2 %u\n",unsleep);
    exit(0);
}

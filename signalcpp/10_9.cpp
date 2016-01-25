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
using namespace std;
void sig_cld(int signo);
int main(int argc, char** argv)
{
    pid_t pid;
    if(signal(SIGCLD,sig_cld)==SIG_ERR)
    {
        perror("error\n"); 
    }
    if((pid=fork())<0)
		perror("fork error\n"); 
    else if(pid==0)
    {
        sleep(2);
        _exit(0);
    }
    pause();
    exit(0);
}
//父子进程信号处理
void sig_cld(int signo)
{
   pid_t pid;
   int status;
   printf("Signal　received\n");
   if(signal(SIGCLD,sig_cld)==SIG_ERR)
   {
       perror("error\n");
   }
   if((pid=wait(&status))<0)
   {
       perror("wait error\n");
   }
   printf("pid=%d\n",pid);
}
/**
void sig_handler(int signo)
{
        struct passwd*                  root_ptr;
        printf("in sig_handler\n");
        root_ptr = getpwnam("root");
        if(root_ptr == NULL){
            perror("sig_usr getpwnam");
            exit(2);
        }
        printf("pw_name = %s\n", root_ptr->pw_name);
        alarm(1);
}
int main(int argc, char** argv)
{
        int                             ret;
        struct passwd*                  ptr;
        signal(SIGALRM, sig_handler);
        alarm(1);
        for(; ;){
            ptr = getpwnam("liujian");
            if(ptr == NULL){
                perror("getpwnam");     
				exit(1);
            }
            if(strcmp(ptr->pw_name, "liujian") != 0){
                printf("return value has corrupted by sig_handler, pw_name = %s\n", ptr->pw_name);
            }
        }
        exit(0);
}
*/

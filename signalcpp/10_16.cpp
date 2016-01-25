/*
sigsuspend的使用
sigprocmask和pause连起来用可以实现sigsuspend的功能；但是还是使用sigsuspend函数，应为sigsuspend是原子操作
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
volatile sig_atomic_t quitflag;


static void sig_handler(int signo)
{
    if(signo==SIGINT)
    {
            printf("\n interruptn-----------\n");
    }
    else if(signo==SIGQUIT)
    {
            quitflag=1;
            printf("\n SIGQUIT quitflag =1\n");
    }
    else if(signo==SIGALRM)
    {
            printf("\n SIGALRM \n");
    }
    printf("\n other sig \n");
}

int main(int argc,char * argv[])
{

    sigset_t newmask,oldmask,zeromask;
    if(signal(SIGINT,sig_handler)==SIG_ERR)
    {
        perror("\n signal(SIGINT) ERROR\n");
    }
    if(signal(SIGQUIT,sig_handler)==SIG_ERR)
    {
        perror("\n signal(SIGQUIT) error\n");
    }
    if(signal(SIGALRM,sig_handler)==SIG_ERR)
    {
        perror("\n signal(SIGALRM) erro\n");
    }
    sigemptyset(&newmask);
    sigemptyset(&zeromask);
    sigaddset(&newmask,SIGQUIT);
    if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)!=0)
    {
        perror("\n sigpromask SIG_BLOCK error\n");
    }
    while(quitflag==0)//while(1)
    {
        //alarm(1);
        if(sigismember(&zeromask,SIGQUIT))//检查挂起信号集合中是否有SIGQUIT
        {
                printf("\n zeromask SIGQUIT pending\n");
        }
        if(sigismember(&newmask,SIGQUIT))//检查挂起信号集合中是否有SIGQUIT
        {
                printf("\n newmask SIGQUIT pending\n");
        }
        if(sigismember(&oldmask,SIGQUIT))//检查挂起信号集合中是否有SIGQUIT
        {
                printf("\n oldmask SIGQUIT pending\n");
        }
        if(sigismember(&zeromask,SIGALRM))//检查挂起信号集合中是否有SIGALRM
        {
                printf("\n zeromask SIGALRM pending\n");
        }
        if(sigismember(&newmask,SIGALRM))//检查挂起信号集合中是否有SIGALRM
        {
                printf("\n newmask SIGALRM pending\n");
        }
        if(sigismember(&oldmask,SIGALRM))//检查挂起信号集合中是否有SIGALRM
        {
                printf("\n oldmask SIGALRM pending\n");
        }
       
        sigsuspend(&zeromask);
        if(sigismember(&zeromask,SIGINT))//检查挂起信号集合中是否有SIGQUIT
        {
                printf("\n zeromask 2 SIGQUIT pending\n");
        }
        if(sigismember(&newmask,SIGQUIT))//检查挂起信号集合中是否有SIGQUIT
        {
                printf("\n newmask 2 SIGQUIT pending\n");
        }
        if(sigismember(&oldmask,SIGQUIT))//检查挂起信号集合中是否有SIGQUIT
        {
                printf("\n oldmask 2 SIGQUIT pending\n");
        }
          if(sigismember(&zeromask,SIGALRM))//检查挂起信号集合中是否有SIGALRM
        {
                printf("\n zeromask 2 SIGALRM pending\n");
        }
        if(sigismember(&newmask,SIGALRM))//检查挂起信号集合中是否有SIGALRM
        {
                printf("\n newmask 2 SIGALRM pending\n");
        }
        if(sigismember(&oldmask,SIGALRM))//检查挂起信号集合中是否有SIGALRM
        {
                printf("\n oldmask 2 SIGALRM pending\n");
        }
    }
    quitflag = 0;
    if(sigprocmask(SIG_SETMASK,&oldmask,NULL)!=0)
    {
            perror("\n sigpromask SIG_SETMASK error\n");
    }
    exit(0);
} 

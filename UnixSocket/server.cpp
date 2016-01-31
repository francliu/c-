#include <stdio.h> 
#include <sys/stat.h> 
#include <sys/socket.h> 
#include <sys/un.h> 
#include <errno.h> 
#include <stddef.h> 
#include <string.h> 
#include <unistd.h> 
// the max connection number of the server 
#define MAX_CONNECTION_NUMBER 5 
    
/* * Create a server endpoint of a connection. * Returns socked if all OK, <0 on error. */ 
int unix_socket_listen(const char *servername) 
{  
    int socked; 
    struct sockaddr_un un;  
    if ((socked = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) 
    { 
        return(-1);  
    } 
    int len, flag_error;  
    unlink(servername);               /* in case it already exists */  
    memset(&un, 0, sizeof(un));  
    un.sun_family = AF_UNIX;  
    strcpy(un.sun_path, servername);  
    len = offsetof(struct sockaddr_un, sun_path) + strlen(servername);  
    /* bind the name to the descriptor */  
    if (bind(socked, (struct sockaddr *)&un, len) < 0) 
    {  
        flag_error = -2;  
    }  
    else 
    { 
        //MAX_CONNECTION_NUMBER表示客户端要入队的数量
        if (listen(socked, MAX_CONNECTION_NUMBER) < 0)     
        {  
            flag_error =  -3;  
        } 
        else 
        { 
            return socked; 
        } 
    } 
    int err; 
    err = errno; 
    close(socked);  
    errno = err; 
    return flag_error;   
} 
    
int unix_socket_accept(int listenfd, uid_t *uidptr) 
{  
    int clifd, len, rval;  
    time_t staletime;  
    //unix高级编程本地通信地址结构
    struct sockaddr_un un; 
    //文件的相关信息结构体，包括设备号，ｉｄ，组号，组ｉｄ等
    struct stat statbuf;  
    len = sizeof(un);  
    if ((clifd = accept(listenfd, (struct sockaddr *)&un, (socklen_t *)&len)) < 0)  
    { 
        return(-1);      
    } 
    /* obtain the client's uid from its calling address */ 
    //获取文件名在结构体重的偏移量，并减去 
    len -= offsetof(struct sockaddr_un, sun_path);  /* len of pathname */ 
    un.sun_path[len] = 0; /* null terminate */
    //stat获取文件名相关的一些基本信息  
    if (stat(un.sun_path, &statbuf) < 0)  
    { 
        rval = -2; 
    }  
    else 
    { 
        //S_ISSOCK判断该文件是否是ｓｏｃｋｅｔ类型
        if (S_ISSOCK(statbuf.st_mode) )  
        {  
            if (uidptr != NULL) *uidptr = statbuf.st_uid;    /* return uid of caller */  
            //解除掉连接便于客户端连接
            unlink(un.sun_path);       /* we're done with pathname now */  
            return clifd;       
        }  
        else 
        { 
            rval = -3;     /* not a socket */  
        } 
    } 
    
    int err; 
    err = errno;  
    close(clifd);  
    errno = err; 
    return(rval); 
} 
    
void unix_socket_close(int fd) 
{ 
    close(fd);      
} 
    
int main(void) 
{  
    int listenfd,connfd;  
    listenfd = unix_socket_listen("foo.sock"); 
    if(listenfd<0) 
    { 
        printf("Error[%d] when listening...\n",errno); 
        return 0; 
    } 
    printf("Now I am listening...%d\n",errno); 
    uid_t uid; 
    connfd = unix_socket_accept(listenfd, &uid); 
    //当连接上之后就不需要监听了，关闭套接字
    unix_socket_close(listenfd);   
    if(connfd<0) 
    { 
        printf("Error[%d] when accepting...\n",errno); 
        return 0; 
    }   
    printf("Begin to recv/send...\n");   
    int i,n,size; 
    char rvbuf[2048]; 
    for(;;) 
    { 
        //===========接收============== 
        size = recv(connfd, rvbuf, 2048, 0);    
        if(size>=0) 
        { 
            // rvbuf[size]='\0'; 
            printf("Recieved Data[%d]:%c...%s\n",size,rvbuf[0],rvbuf); 
        } 
        if(size==-1) 
        { 
            printf("Error[%d] when recieving Data:%s.\n",errno,strerror(errno));     
            break;      
        } 
        sleep(1); 
    } 
    unix_socket_close(connfd); 
    printf("Server exited.\n");     
} 

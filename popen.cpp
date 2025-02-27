/*************************************************************************
    > File Name: popen.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月28日 星期四 10时48分15秒
 ************************************************************************/

#include <sys/types.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>

int main( void )  
{  
    FILE   *stream;  
    FILE    *wstream;
    char   buf[1024];
    
    memset( buf, '0', sizeof(buf) );//初始化buf,以免后面写如乱码到文件中
    stream = popen( "ls -l", "r" ); //将“ls －l”命令的输出 通过管道读取（“r”参数）到FILE* stream
    wstream = fopen( "bian_file.txt", "w+"); //新建一个可写的文件

    fread( buf, sizeof(char), sizeof(buf),  stream);  //将刚刚FILE* stream的数据流读取到buf中
    fwrite( buf, 1, sizeof(buf), wstream );//将buf中的数据写到FILE    *wstream对应的流中，也是写到文件中
   
    pclose( stream ); 
    fclose( wstream );
   
    return 0;
}   

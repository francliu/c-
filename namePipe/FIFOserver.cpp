#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>

int main()
{
	const char *fifo_name = "/tmp/my_fifo";
	int read_fd = -1;
	int write_fd = -1;
	int res = 0;
	int open_mode = O_RDONLY;
	char buffer[PIPE_BUF + 1];
	int bytes_read = 0;
	int bytes_write = 0;
	//清空缓冲数组
	memset(buffer, '\0', sizeof(buffer));

	printf("Process %d opening FIFO O_RDONLY\n", getpid());
	//以只读阻塞方式打开管道文件，注意与fifowrite.c文件中的FIFO同名
	read_fd = open(fifo_name, open_mode);
	//以只写方式创建保存数据的文件
	write_fd = open("DataFormFIFO.txt", O_WRONLY|O_CREAT, 0644);
	printf("Process %d result %d\n",getpid(), read_fd);

	if(read_fd != -1)
	{
		do
		{
			//读取FIFO中的数据，并把它保存在文件DataFormFIFO.txt文件中
			res = read(read_fd, buffer, PIPE_BUF);
			bytes_write = write(write_fd, buffer, res);
			bytes_read += res;
		}while(res > 0);
		close(read_fd);
		close(write_fd);
	}
	else
		exit(EXIT_FAILURE);

	printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
	exit(EXIT_SUCCESS);
}
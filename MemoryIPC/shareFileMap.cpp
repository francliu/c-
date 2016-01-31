/*
 * Posix shared memory is easy to use in Linux 2.6, in this program, we 
 * shared a memory between parent process and child process, stored several
 * objects of struct namelist in it. We store number of items in ptr[0].
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_MODE (S_IRUSR | S_IWUSR)

const char shmfile[] = "./tmp.sh";
//const char shmfile[] = "/dev/zero";
const int size = 100;

struct namelist 
{
 int  id;
 int  test;
 char name[20];
};

int main(void)
{
 int fd, pid, status; 
 int *ptr;
 struct stat stat;
  
 // create a Posix shared memory
 int flags = O_RDWR | O_CREAT;
 fd = open(shmfile, flags, FILE_MODE);
 ftruncate(fd, size);//把fd指定为size大小
 ptr = (int *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
 printf("start:%p\n",ptr);
 printf("end:%p\n",&ptr[size]);
 close(fd);
 pid = fork();
 if (pid == 0) { // child process
  printf("Child %d: start\n", getpid());
  
  fd = open(shmfile, flags, FILE_MODE);
  fstat(fd, &stat);  
  ptr = (int *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
  close(fd);
  struct namelist tmp;

  // store total num in ptr[0];
  *ptr = 3;
  
  ptr++;
  int num=0;
  while(num<10)
  {
	 num++;
	 namelist *cur = (namelist *)ptr;
		// store items
	 tmp.id = num;
	 tmp.test=1.0;
	 strcpy(tmp.name, "Nellson");
	 *cur++ = tmp;
	 tmp.id = num;
	 tmp.test=2.0;
	 strcpy(tmp.name, "Daisy");
	 *cur++ = tmp;
	 tmp.id = num;
	 tmp.test=3.0;
	 strcpy(tmp.name, "Robbie");
	 *cur++ = tmp;
	 sleep(3);
  }
  exit(0);
 } else{ // parent process
  sleep(3);
  int num=0;
  while(num<10)
  {
	 struct namelist tmp;
     int *t = ptr;
	 num++;
	 int total = *t;
	 printf("\nThere is %d item in the shm\n", total);
	 t++;
	 namelist *cur = (namelist *)t;
	 for (int i = 0; i< total; i++) 
	 {
	    tmp = *cur;
		printf("%d:%s\n", tmp.id, tmp.name);
		cur++;
	 }
	 sleep(3);
  }
  printf("\n");
  waitpid(pid, &status, 0);
 }
 printf("Parent %d get child status:%d\n", getpid(), status);
 return 0;
}


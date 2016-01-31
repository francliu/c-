/*
 * System V shared memory in easy to use in Linux 2.6, in this program, we 
 * shared a memory between parent process and child process, stored several
 * objects of struct namelist in it. We store number of items in ptr[0].
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SVSHM_MODE (SHM_R | SHM_W | SHM_R>>3 | SHM_R>>6)
const char shmfile[] = "./tmp.shmk";
const int shmsize = 10;

struct namelist 
{
 int  id; 
 char name[20];
};

int 
main(void)
{
 int shmid, pid, status; 
 int *ptr;
 struct shmid_ds buff;

 // create a systym V shared memory
 //shmid = shmget(ftok(shmfile, 0), shmsize, SVSHM_MODE | IPC_CREAT);
 shmid = shmget((key_t)0x12345678, shmsize, SVSHM_MODE | IPC_CREAT);

 pid = fork();
 if (pid == 0) { // child process
  printf("Child %d: start\n", getpid());
  //shmid = shmget(ftok(shmfile, 0), shmsize, SVSHM_MODE | IPC_CREAT);
  shmid = shmget((key_t)0x12345678, shmsize, SVSHM_MODE | IPC_CREAT);
  ptr = (int *) shmat(shmid, NULL, 0);
  shmctl(shmid, IPC_STAT, &buff);

  struct namelist tmp;

  // store total num in ptr[0];
  *ptr = 3;
  
  ptr++;
  int num=0;
  while(num<10)
  {
	  num++;
  struct namelist *cur = (namelist *)ptr;

  // store items
  tmp.id = num;
  strcpy(tmp.name, "Nellson");
  *cur++ = tmp;
  tmp.id = num;
  strcpy(tmp.name, "Daisy");
  *cur++ = tmp;
  tmp.id = num;
  strcpy(tmp.name, "Robbie");
  *cur++ = tmp;
  sleep(2);
  }
  exit(0);
 } else{ // parent process
  sleep(2);
  shmctl(shmid, IPC_STAT, &buff);
  int num=0;
  while(num<10)
  {
  ptr = (int *) shmat(shmid, NULL, 0); 
  struct namelist tmp;
  int *t=ptr;
	  num++;
  int total = 3;
  printf("\nThere is %d item in the shm\n", total); 
  
  t++;
  struct namelist *cur = (namelist *)t;

  for (int i = 0; i< total; i++) {
   tmp = *cur;
   printf("%d: %s\n", tmp.id, tmp.name);
   cur++;
  }
  sleep(1);
  }

  printf("\n");
  waitpid(pid, &status, 0);
 }

 // remvoe a systym V shared memory from system
 shmctl(shmid, IPC_RMID, NULL);
 printf("Parent %d get child status:%d\n", getpid(), status);
 return 0;
}
 

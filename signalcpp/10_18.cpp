#include 
#include 
#include 
#include 

int system(const char * cmdstring) 
{ 
pid_t pid; 
int status; 

if(cmdstring == NULL){ 

return (1); 
} 


if((pid = fork())<0){ 

status = -1; 
} 
else if(pid == 0){ 
execl("/bin/sh", "sh", "-c", cmdstring, (char *)0); 
_exit(127); //子进程正常执行则不会执行此语句 
} 
else{ 
while(waitpid(pid, &status, 0) < 0){ 
if(errno != EINTER){ 
status = -1; 
break; 
} 
} 
} 
return status; 
}
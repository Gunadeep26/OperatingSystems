#include <sys/ipc.h>
# define NULL 0
#include <sys/shm.h>
#include <sys/types.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
#include <sys/wait.h>
#include <stdio_ext.h>
// parent writing a char in shared memory and child reads it and prints it.
int main()
{
int pid;
char *a,*b,*c;
int id,n,i,new_id;
// you can create a shared memory between parent and child here or you can //create inside them separately.
id=shmget(111,50,IPC_CREAT | 00666);
new_id=shmget(112,50,IPC_CREAT | 00666);
c=shmat(new_id,NULL,0);
c[0]='n';
a=shmat(id,NULL,0);
scanf("%s",a);
c[0]='y';

}

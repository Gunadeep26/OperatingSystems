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

int main()
{
int pid,new_id;
char *a,*b,*c;
int id,n,i;
id=shmget(111,50,IPC_CREAT | 00666);
new_id=shmget(112,50,0);
b=shmat(id,NULL,0);
c=shmat(new_id,NULL,0);
while(c[0]=='n');
for(int i=0;i<strlen(b);i++)
	printf("%c",b[i]-32);
wait(NULL);
shmdt(b);
shmdt(c);
shmctl(id, IPC_RMID,NULL);
shmctl(new_id, IPC_RMID,NULL);
}

#include<stdio.h>
#include<stdlib.h>
#define buffsize 1024
int main(int argc, char * argv[]){

char src,dest,nbread,nbwrite;
char * buff[buffsize];

if(argc != 3 || argv[1] == "--help")
{
printf("destination file not found");
exit(1);
}
src=open(argv[1]);
if(src == -1){
printf("file not found");
}
dest = open(argv[2]);
if(dest == -1){
printf("error opening file");
exit(1);
}

	while((nbread = read(src,buff,buffsize)) > 0)
	{
		if(write(dest,buff,nbread) != nbread)
			printf("\nError in writing data to %s\n",argv[2]);
	}
	
	if(nbread == -1)
		printf("\nError in reading data from %s\n",argv[1]);
	
	if(close(src) == -1)
		printf("\nError in closing file %s\n",argv[1]);
 
	if(close(dest) == -1)
		printf("\nError in closing file %s\n",argv[2]);
 
	exit(EXIT_SUCCESS);
}

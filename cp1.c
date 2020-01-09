
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>

int main(int argc, char *argv[]){
	int f1,f2;
	char input[3];
	char temp[10000];
	long int n;
 	int arg1=1,arg2=2;
	if(argc==4){
		arg1=2;
		arg2=3;
	}
	if(argc>4){
		printf("ERROR: More number of arguments are given...!\n");
		exit(0);
	}
        if(argc==0){
		printf("ERROR: No input arguments given ...!\n");
		exit(0);
	}
	f1=open(argv[arg1], O_RDONLY);
	if(f1==-1){
		printf("ERROR: The Source file '%s' does not exist...!\n",argv[arg2]);
		exit(0);
	}
	n=read(f1,temp,10000);
	if(n>=1){
		if(strcmp(argv[1],"-i")==0){
			printf("Do you want to copy the file?");
			scanf("%s",input);
			if(strcmp(input,"n")==0||strcmp(input,"no")==0){
				exit(1);
			}
			if(strcmp(input,"yes")!=0 && strcmp(input,"y")!=0){
				printf("invalid input...!\n");
				exit(1);
			}
		}
		f2=open(argv[arg2],O_CREAT|O_WRONLY|O_TRUNC);
		write(f2,temp,n);	
		printf("The File Copied Successfully!!\n");
	}
	else if(n==0){
		printf("The file is empty...!\n");
	}
}

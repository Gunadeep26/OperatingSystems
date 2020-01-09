
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

	if(argc>=3){
		printf("ERROR: More number of arguments are given...!\n");
		exit(0);
	}

	if(argv[1]!=NULL){
		struct dirent *dir;
		DIR *d;
		d=opendir(argv[1]);
		if(d==NULL){
			printf("ERROR: The Directory '%s' does not exist...!\n",argv[1]);
			exit(0);
		}
		while ((dir = readdir(d)) != NULL) 
			printf("%s\n",dir->d_name);
	}

	else{
		printf("ERROR: No directory name input is given...!\n");
	}
}

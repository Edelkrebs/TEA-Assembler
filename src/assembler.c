#include <stdio.h>
#include <fileio.h>

int main(int argc, char* argv[]){

	if(argc == 2){
		printf("Assembling file: %s\n", argv[1]);
	}else{
		printf("No input files specified. Aborting.\n");
	}

	printf("%d\n",((0x6D << 24) | ((0x4400 & 0xFF) << 8) | (0x4400 & ~0xFF)));

	return 0;	

}
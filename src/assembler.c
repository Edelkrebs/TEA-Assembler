#include <stdio.h>
#include <fileio.h>
#include <instruction/instruction.h>

int main(int argc, char* argv[]){

	if(argc == 2){
		printf("Assembling file: %s\n", argv[1]);
	}else{
		printf("No input files specified. Aborting.\n");
	}

	readFileToBuffer(argv[1]);
	printf("%s\n", file_buffer[0]);
	initInstructionset();

	return 0;	

}
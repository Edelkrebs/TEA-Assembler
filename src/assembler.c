#include <stdio.h>
#include <fileio.h>
#include <instruction/instruction.h>

int main(int argc, char* argv[]){

	if(argc == 2){
		printf("Assembling file: %s\n", argv[1]);
	}else{
		printf("No input files specified. Aborting.\n");
	}

	initInstructionset();
	printf("%p\n", getInstruction("ADC"));

	return 0;	

}
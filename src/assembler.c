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
	uint8_t* opcode_str = generate_opcode_string(3, ABSOLUTE, 0x6D, 0x4400);

	printf("%x", opcode_str[0]);
	printf("%x", opcode_str[1]);
	printf("%x", opcode_str[2]);
	printf("\n");

	return 0;	

}
#include <stdio.h>
#include <fileio.h>
#include <instruction/instruction.h>
#include <parser.h>

int main(int argc, char* argv[]){

	if(argc == 2){
		printf("Assembling file: %s\n", argv[1]);
	}else{
		printf("No input files specified. Aborting.\n");
	}

	readFileToBuffer(argv[1]);
	initInstructionset();

	for(int i = 0; i < line_count; i++){
		parse_line(file_buffer[i]);
	}

	return 0;	

}
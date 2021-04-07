#include <stdio.h>
#include <stdlib.h>
#include <fileio.h>
#include <instruction/instruction.h>
#include <parser.h>

uint16_t assembled_code_index;
uint8_t* assembled_code;

int main(int argc, char* argv[]){

	assembled_code_index = 0;

	assembled_code = (uint8_t*) malloc(16392 * sizeof(uint8_t));

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

	for(int i = 0; i < assembled_code_index; i++){
		printf("%x\n", assembled_code[i]);
	}

	return 0;	

}
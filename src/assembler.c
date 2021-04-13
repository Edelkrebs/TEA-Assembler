#include <stdio.h>
#include <stdlib.h>
#include <fileio.h>
#include <instruction/instruction.h>
#include <parser.h>

#include <string.h>

uint16_t assembled_code_index = 0;
uint8_t* assembled_code;
uint16_t origin = 0;
char* labels[8192];
uint16_t labels_index = 0;

int main(int argc, char* argv[]){

	assembled_code = (uint8_t*) malloc(16392 * sizeof(uint8_t));

	if(argc == 2){
		printf("Assembling file: %s\n", argv[1]);
	}else{
		printf("No input files specified. Aborting.\n");
	}

	readFileToBuffer(argv[1]);
	initInstructionset();

	parsing_state = PREPROCESSING;
	for(int i = 0; i < line_count; i++){
		parse_line(file_buffer[i]);
	}

	assembled_code_index = 0;
	line_number = 0;

	parsing_state = ASSEMBLING;
	for(int i = 0; i < line_count; i++){
		parse_line(file_buffer[i]);
	}

	for(int i = 0; i < assembled_code_index; i++){
		printf("%x\n", assembled_code[i]);
	}

	for(int i = 0; i < 8192; i++){
		free(labels[i]);
	}

	free(assembled_code);

	return 0;	

}
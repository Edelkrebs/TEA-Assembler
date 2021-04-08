#include <parser.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <instruction/instruction.h>
#include <fileio.h>

extern uint8_t* assembled_code;
extern uint16_t assembled_code_index;

void error(const char* message){
	printf("[ERROR] at line: %d\n%s\nWith message:\n%s\n", line_number, file_buffer[line_number - 1],  message);
	exit(-1);
}

uint16_t getArgument(const char* line, MODES mode){  //TODO: Rewrite bc sucks
	uint16_t dollar_sign = 0;
	uint16_t argument = 0;
	while(line[dollar_sign] != '$') dollar_sign++; 
	dollar_sign++;
	int shift_index = (getSize(mode) - 1) * 2 - 1;
	for(int i = 0; i < (getSize(mode) - 1) * 2; i++){
		if(line[i + dollar_sign] >= '0' && line[i + dollar_sign] <= '9'){
			argument |= (line[i + dollar_sign] - '0') << (4 * shift_index);  
			shift_index--;
		}else if(line[i + dollar_sign] >= 'A' && line[i + dollar_sign] <= 'F'){
			argument |= (line[i + dollar_sign] - 'A' + 10) << (4 * shift_index);  
			shift_index--;
		}else if(line[i + dollar_sign] >= 'a' && line[i + dollar_sign] <= 'f'){
			argument |= (line[i + dollar_sign] - 'a' + 10) << (4 * shift_index);  
			shift_index--;
		}
	}
	return argument;
}

MODES getMode(const char* line){
	int line_len = strlen(line);
	char* argument = (char*) malloc(line_len); 
	memcpy(argument, line + 3, line_len);
	int argument_len = strlen(argument);
	//printf("%s\n", argument);
	//printf("Line len: %d\n", (int) strlen(argument));
	switch(argument[0]){
		case '#':{
			if(argument[1] == '$')return IMMEDIATE;
			else error("Invalid immediate addressing mode argument!");
		}	
		case 'A': {
			return ACCUMULATOR;
		}case '$':{
			if(argument_len <= 6 && argument[argument_len - 2] == ','){
				if(argument[argument_len - 1] == 'X'){
					return ZERO_PAGE_X;
				}else if(argument[argument_len - 1] == 'Y'){
					return ZERO_PAGE_Y;
				}else if(argument[argument_len - 1] != 'Y' && argument[argument_len - 1] != 'X'){
					error("Invalid zero page addressing mode!");
				}
			}else if(argument_len >= 6 && argument[argument_len - 2] == ','){
				if(argument[argument_len - 1] == 'X'){
					return ABSOLUTE_X;
				}else if(argument[argument_len - 1] == 'Y'){
					return ABSOLUTE_Y;
				}
			}else if(argument_len <= 3){
				return ZERO_PAGE;
			}else if(argument_len > 3){
				return ABSOLUTE;
			}	
		}case '(':{
			if(argument[argument_len - 1] == ')'){
				if(argument[argument_len - 2] == 'X'){
					return INDIRECT_X;
				}else{
					return ABSOLUTE_INDIRECT;	
				} 
			}else if(argument[argument_len - 1] == 'Y'){
				return INDIRECT_Y;
			}
		}
		default:{
			return -1;
		}
	}
	error("Could not get addressing mode!");
	return ABSOLUTE;
}

void parse_line(const char* line){
	line_number++;
	char* opcode = (char*) malloc(4 * sizeof(char));
	MODES mode;
	uint8_t size = 0;
	uint16_t argument = 0;
	char* without_whitespaces = (char*) malloc(strlen(line) * sizeof(char));
{
	int i = 0, j = 0;
	while(line[i]){
		if(line[i] != ' '){
			without_whitespaces[j++] = line[i];
		}
		i++;
	}
	without_whitespaces[j] = '\0';
}
	memcpy(opcode, without_whitespaces, 3);
	opcode[3] = '\0';

	if(getInstruction(opcode) == NULL) error("Unrecognized instruction!");

	if(strlen(without_whitespaces) >= 4){
		mode = getMode(without_whitespaces);
	}else{
		mode = IMPLIED;
	}

	if(mode == -1){
		error("Couldnt guess addressing mode!");
	}
	
	if(getInstruction(opcode)->opcode(mode) == 0xFF){
		error("Addressing mode not supported by instruction!");
	}
	
	size = getSize(mode);
	if(mode != ACCUMULATOR && mode != IMPLIED)argument = getArgument(line, mode);
	uint8_t* opcode_string = generate_opcode_string(size, mode, getInstruction(opcode)->opcode(mode), argument);
	
	for(int i = 0; i < size; i++){
		assembled_code[assembled_code_index + i] = opcode_string[i];
	}
	
	assembled_code_index += size;
}
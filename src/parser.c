#include <parser.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <instruction/instruction.h>

MODES getMode(const char* line){
	int line_len = strlen(line);
	char* argument = (char*) malloc(line_len - 3); 
	memcpy(argument, line + 3, line_len - 3);
	int argument_len = strlen(argument);
	switch(argument[0]){
		case '#': return IMMEDIATE;
		case 'A': return ACCUMULATOR;
		case '$':{
			if(argument_len < 6 && argument[argument_len - 2] == ','){
				if(argument[argument_len - 1] == 'X'){
					return ZERO_PAGE_X;
				}else if(argument[argument_len - 1] == 'Y'){
					return ZERO_PAGE_Y;
				}
			}else if(argument_len >= 6 && argument[argument_len - 2] == ','){
				if(argument[argument_len - 1] == 'X'){
					return ABSOLUTE_X;
				}else if(argument[argument_len - 1] == 'Y'){
					return ABSOLUTE_Y;
				}
			}else if(argument_len < 4){
				return ZERO_PAGE;
			}else if(argument_len > 4){
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
			printf("ERROR: Couldn't guess addressing mode!\n");
			exit(-1);
		}
	}
	return ABSOLUTE;
}

uint8_t* parse_line(const char* line){
	char* opcode = (char*) malloc(4 * sizeof(char));
	MODES mode = IMPLIED;
	uint8_t size = 0;

	char* without_whitespaces = (char*) malloc(strlen(line) * sizeof(char));
	int whitespace_index = 0;
	for(int i = 0; i < strlen(line) - 1; i++){
		if(line[i] == ';'){
			whitespace_index++;
			break;
		}
		if(line[i] != ' ' && line[i] != '\0' && line[i] != '\n' && line[i] != '\t'){
			without_whitespaces[whitespace_index] = line[i];
			whitespace_index++;
		}
	}

	without_whitespaces[whitespace_index] = '\0';
	memcpy(opcode, without_whitespaces, 3);
	opcode[3] = '\0';

	if(strlen(without_whitespaces) > 3){
		mode = getMode(without_whitespaces);
	}else{
		mode = IMPLIED;
	}
	
	size = getSize(mode);
	size++;
	
	return 0;
}
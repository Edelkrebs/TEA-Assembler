#include <parser.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <instruction/instruction.h>

uint8_t* parse_line(const char* line){
	char* opcode = (char*) malloc(4 * sizeof(char));
	MODES mode = IMPLIED;

	char* without_whitespaces = (char*) malloc(strlen(line) * sizeof(char));
	int whitespace_index = 0;
	for(int i = 0; i < strlen(line) - 1; i++){
		if(line[i] != ' ' && line[i] != '\0' && line[i] != '\n' && line[i] != '\t'){
			without_whitespaces[whitespace_index] = line[i];
			whitespace_index++;
		}
	}

	without_whitespaces[whitespace_index] = '\0';
	memcpy(opcode, without_whitespaces, 3);
	opcode[3] = '\0';

	if(strlen(without_whitespaces) > 3){
		switch(without_whitespaces[3]){
			case '#': {
				mode = IMMEDIATE;
			}case '$'{
				
			}case '('{
				
			}
		}
	}else{
		printf("DDDD");
	}
	
	return 0;
}
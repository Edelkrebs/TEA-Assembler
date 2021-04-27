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
extern char* labels[];
extern uint16_t labels_index;

void error(const char* message){
	printf("[ERROR] at line: %d\n%s\nWith message:\n%s\n", line_number, file_buffer[line_number - 1],  message);
	exit(-1);
}

LINE_TYPE getLineType(const char* line){
	uint16_t special_char_index = 0;
	while(line[special_char_index] != ':' && line[special_char_index] != '=' && line[special_char_index] != '.' && special_char_index != strlen(line)) special_char_index++;
	if(special_char_index == strlen(line)) return INSTRUCTION;
	if(line[special_char_index] == ':'){
		return LABEL;
	}else if(line[special_char_index] == '='){
	}else if(line[special_char_index] == '.'){
		return DIRECTIVE;
		return VARIABLE;
	}
	return INVALID_LINE;
}

int16_t getArgument(const char* line, MODES mode){  //TODO: Rewrite bc sucks
	uint16_t dollar_sign = 0;
	int16_t argument = 0;
	if(strchr(line, '$') == 0){
		char* argument_str = (char*) malloc(strlen(line));
		memcpy(argument_str, line + 3, strlen(line));
		for(int i = 0; i < labels_index; i++){
			if(mode == RELATIVE){
				if(strcmp(labels[i], argument_str) == 0){
					if(assembled_code_index > argument){
						argument = argument - assembled_code_index;
						return argument;
					}else{
						argument = assembled_code_index - argument;
						return ~argument;
					}
				}
			}else if(mode == ABSOLUTE){
				if(strcmp(labels[i], argument_str) == 0){
					argument |= labels[i][strlen(labels[i]) + 1];
					argument |= labels[i][strlen(labels[i]) + 2] << 8;
					return argument;
				}
			}
		}
	}
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
				if(line[0] == 'B') return RELATIVE;
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
			if(line[0] == 'B'){
				return RELATIVE;	
			} 
			if(line[0] == 'J'){
				return ABSOLUTE;	
			} 
			return -1;
		}
	}
	free(argument);
	error("Could not get addressing mode!");
	return ABSOLUTE;
}

void processInstruction(const char* without_whitespaces){
	char* opcode = (char*) malloc(4 * sizeof(char));
	MODES mode;
	uint8_t size = 0;
	uint16_t argument = 0;

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
	if(parsing_state != PREPROCESSING){
		if(mode != ACCUMULATOR && mode != IMPLIED)argument = getArgument(without_whitespaces, mode);
	}
	uint8_t* opcode_string = generate_opcode_string(size, mode, getInstruction(opcode)->opcode(mode), argument);
	if(parsing_state != PREPROCESSING){
		for(int i = 0; i < size; i++){
			assembled_code[assembled_code_index + i] = opcode_string[i];
		}	
	}
		
	assembled_code_index += size;
	free(opcode_string);
	free(opcode);
}

void processVariable(const char* without_whitespaces){
	
}

void processLabel(const char* without_whitespaces){ // The last 2 bytes of the null terminated label are the position of the label in memory
	char* label_name = (char*) malloc(strlen(without_whitespaces) + 2);
	memcpy(label_name, without_whitespaces, strlen(without_whitespaces) - 1);
	uint8_t label_len = strlen(without_whitespaces);
	label_name[label_len - 1] = '\0';
	label_name[label_len] =  assembled_code_index << 8;
	label_name[label_len + 1] =  (char)assembled_code_index;
	if(labels_index > 0){
		for(int i = 0; i < labels_index; i++){
			if(strcmp(labels[i], label_name) == 0){
				error("Redefined label");
			}
		}	
	}
	labels[labels_index] = label_name;
	labels_index++;
}

void processDirective(const char* without_whitespaces){
	
}

void parse_line(const char* line){
	line_number++;
	LINE_TYPE linetype;
	char* without_whitespaces = (char*) malloc(strlen(line) * sizeof(char));
{
	int i = 0, j = 0;
	while(line[i]){
		if(line[i] != ' ' && line[i] != '\t'){
			if(line[i] == ';') break;
			without_whitespaces[j++] = line[i];
		}
		i++;
	}
	without_whitespaces[j] = '\0';
}
	linetype = getLineType(without_whitespaces);

	if(linetype == INVALID_LINE) error("Undefined syntax error.");

	switch(linetype){
		case INSTRUCTION:{
			processInstruction(without_whitespaces);
			break;
		}case VARIABLE:{
			if(parsing_state != ASSEMBLING)processVariable(without_whitespaces);
			break;
		}case LABEL:{
			if(parsing_state != ASSEMBLING)processLabel(without_whitespaces);
			break;
		}case DIRECTIVE:{
			if(parsing_state != ASSEMBLING)processDirective(without_whitespaces);
			break;
		}default: error("Wtf? It isnt supposed to reach this.");
	}
	free(without_whitespaces);
}
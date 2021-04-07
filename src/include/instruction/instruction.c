#include <instruction/instruction.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

uint8_t getSize(MODES mode){
	switch(mode){
		case ACCUMULATOR: {
			return 1;
		}case IMMEDIATE: {
			return 2;
		}case ZERO_PAGE: {
			return 2;
		}case ZERO_PAGE_X: {
			return 2;
		}case ZERO_PAGE_Y: {
			return 2;
		}case IMPLIED: {
			return 1;
		}case RELATIVE: {
			return 2;
		}case ABSOLUTE: {
			return 3;
		}case ABSOLUTE_X: {
			return 3;
		}case ABSOLUTE_Y: {
			return 3;
		}case INDIRECT_X: {
			return 2;
		}case INDIRECT_Y: {
			return 2;
		}case ABSOLUTE_INDIRECT: {
			return 3;
		}
	}
	return 0;
}

uint8_t* generate_opcode_string(uint8_t size, MODES mode, uint8_t opcode, uint16_t argument){
	if(((mode == ABSOLUTE) && (size != 3)) || ((mode == ABSOLUTE_X) && (size != 3)) || ((mode == ABSOLUTE_Y) && (size != 3))){
		printf("Invalid operation size.Aborting\n");
		exit(-1);
	}
	uint8_t* opcode_string = (uint8_t*) malloc(size * sizeof(uint8_t));
	switch(mode){
		case ACCUMULATOR:{
			opcode_string[0] = opcode;
			return opcode_string;
		}case IMMEDIATE: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)argument;
			return opcode_string;
		}case ZERO_PAGE: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)argument;
			return opcode_string;
		}case ZERO_PAGE_X: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)argument;
			return opcode_string;
		}case ZERO_PAGE_Y: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)argument;
			return opcode_string;
		}case IMPLIED: {	
			opcode_string[0] = opcode;
			return opcode_string;
		}case RELATIVE: {	
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)argument;
			return opcode_string;
		}case ABSOLUTE: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			opcode_string[2] = (uint8_t)(argument >> 8);
			return opcode_string;
		}case ABSOLUTE_X: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			opcode_string[2] = (uint8_t)(argument >> 8);
			return opcode_string;
		}case ABSOLUTE_Y: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			opcode_string[2] = (uint8_t)(argument >> 8);
			return opcode_string;
		}case INDIRECT_X: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			return opcode_string;
		}case INDIRECT_Y: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			return opcode_string;
		}case ABSOLUTE_INDIRECT: {	
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			opcode_string[2] = (uint8_t)(argument >> 8);
			return opcode_string;
		}default:{
			return 0;
		}
	}
}

void initInstructionset(){
	for(int i = 0; i < 255; i++){
		instructionset[i] = (Instruction*) NULL;
	}
	REGISTER_INSTRUCTION(ADC, 0);
	REGISTER_INSTRUCTION(AND, 1);
	REGISTER_INSTRUCTION(ASL, 2);
	REGISTER_INSTRUCTION(BIT, 3);
	REGISTER_INSTRUCTION(BPL, 4);
	REGISTER_INSTRUCTION(BMI, 5);
	REGISTER_INSTRUCTION(BVC, 6);
	REGISTER_INSTRUCTION(BVS, 7);
	REGISTER_INSTRUCTION(BCC, 8);
	REGISTER_INSTRUCTION(BCS, 9);
	REGISTER_INSTRUCTION(BNE, 10);
	REGISTER_INSTRUCTION(BEQ, 11);
	REGISTER_INSTRUCTION(BRK, 12);
}

Instruction* getInstruction(const char* name){
	for(int i = 0; i < 255; i++){
		if(instructionset[i] != NULL){
			if(strcmp(instructionset[i]->name, name) == 0){
				return instructionset[i];
			}
		}
	}
	return NULL;
}
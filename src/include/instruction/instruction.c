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
	REGISTER_INSTRUCTION(CMP, 13);
	REGISTER_INSTRUCTION(CPX, 14);
	REGISTER_INSTRUCTION(CPY, 15);
	REGISTER_INSTRUCTION(DEC, 16);
	REGISTER_INSTRUCTION(CLC, 17);
	REGISTER_INSTRUCTION(SEC, 18);
	REGISTER_INSTRUCTION(CLI, 19);
	REGISTER_INSTRUCTION(SEI, 20);
	REGISTER_INSTRUCTION(CLV, 21);
	REGISTER_INSTRUCTION(CLD, 22);
	REGISTER_INSTRUCTION(SED, 23);
	REGISTER_INSTRUCTION(INC, 24);
	REGISTER_INSTRUCTION(JMP, 25);
	REGISTER_INSTRUCTION(JSR, 26);
	REGISTER_INSTRUCTION(LDA, 27);
	REGISTER_INSTRUCTION(LDX, 28);
	REGISTER_INSTRUCTION(LDY, 29);
	REGISTER_INSTRUCTION(LSR, 30);
	REGISTER_INSTRUCTION(NOP, 31);
	REGISTER_INSTRUCTION(ORA, 32);
	REGISTER_INSTRUCTION(TAX, 33);
	REGISTER_INSTRUCTION(TXA, 34);
	REGISTER_INSTRUCTION(DEX, 35);
	REGISTER_INSTRUCTION(INX, 36);
	REGISTER_INSTRUCTION(TAY, 37);
	REGISTER_INSTRUCTION(TYA, 38);
	REGISTER_INSTRUCTION(DEY, 39);
	REGISTER_INSTRUCTION(INY, 40);
	REGISTER_INSTRUCTION(ROL, 41);
	REGISTER_INSTRUCTION(ROR, 42);
	REGISTER_INSTRUCTION(RTI, 43);
	REGISTER_INSTRUCTION(RTS, 44);
	REGISTER_INSTRUCTION(SBC, 45);
	REGISTER_INSTRUCTION(STA, 46);
	REGISTER_INSTRUCTION(TXS, 47);
	REGISTER_INSTRUCTION(TSX, 48);
	REGISTER_INSTRUCTION(PHA, 49);
	REGISTER_INSTRUCTION(PLA, 50);
	REGISTER_INSTRUCTION(PHP, 51);
	REGISTER_INSTRUCTION(PLP, 52);
	REGISTER_INSTRUCTION(STX, 53);
	REGISTER_INSTRUCTION(STY, 54);
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
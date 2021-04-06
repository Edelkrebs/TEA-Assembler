#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0x29;
		}case ZERO_PAGE: {
			return 0x25;
		}case ZERO_PAGE_X: {
			return 0x35;
		}case ABSOLUTE: {
			return 0x2D;
		}case ABSOLUTE_X: {
			return 0x3D;
		}case ABSOLUTE_Y: {
			return 0x39;
		}case INDIRECT_X: {
			return 0x21;
		}case INDIRECT_Y: {
			return 0x31;
		}default:{
			return -1;
		}
	}
}

static uint8_t size(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 2;
		}case ZERO_PAGE: {
			return 2;
		}case ZERO_PAGE_X: {
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
		}default:{
			return -1;
		}
	}
}

__attribute__((unused)) static uint8_t* decode_instruction(uint16_t argument, MODES mode){
	return generate_opcode_string(size(mode), mode, opcode(mode), argument);
}

Instruction* registerANDInstruction(){
	Instruction* and = (Instruction*) malloc(sizeof(Instruction));
	and->name = "AND";
	and->modes_count = 8;
	and->modes = (MODES*) malloc(and->modes_count * sizeof(int));
	and->modes[0] = IMMEDIATE;
	and->modes[1] = ZERO_PAGE;
	and->modes[2] = ZERO_PAGE_X;
	and->modes[3] = ABSOLUTE;
	and->modes[4] = ABSOLUTE_X;
	and->modes[5] = ABSOLUTE_Y;
	and->modes[6] = INDIRECT_X;
	and->modes[7] = INDIRECT_Y;
	and->opcode = &opcode;
	and->size = &size;	
	and->decode_instruction = &decode_instruction;
	return and;
}

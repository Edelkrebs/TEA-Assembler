#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ACCUMULATOR: {
			return 0x0A;
		}case ZERO_PAGE: {
			return 0x06;
		}case ZERO_PAGE_X: {
			return 0x16;
		}case ABSOLUTE: {
			return 0x0E;
		}case ABSOLUTE_X: {
			return 0x1E;
		}default:{
			return -1;
		}
	}
}

static uint8_t size(MODES mode){
	switch(mode){
		case ACCUMULATOR: {
			return 1;
		}case ZERO_PAGE: {
			return 2;
		}case ZERO_PAGE_X: {
			return 2;
		}case ABSOLUTE: {
			return 3;
		}case ABSOLUTE_X: {
			return 3;
		}default:{
			return -1;
		}
	}
}

__attribute__((unused)) static uint8_t* decode_instruction(uint16_t argument, MODES mode){
	return generate_opcode_string(size(mode), mode, opcode(mode), argument);
}

Instruction* registerASLInstruction(){
	Instruction* asl = (Instruction*) malloc(sizeof(Instruction));
	asl->name = "ASL";
	asl->modes_count = 5;
	asl->modes = (MODES*) malloc(asl->modes_count * sizeof(int));
	asl->modes[0] = ACCUMULATOR;
	asl->modes[1] = ZERO_PAGE;
	asl->modes[2] = ZERO_PAGE_X;
	asl->modes[3] = ABSOLUTE;
	asl->modes[4] = ABSOLUTE_X;
	asl->opcode = &opcode;
	asl->size = &size;	
	asl->decode_instruction = &decode_instruction;
	return asl;
}

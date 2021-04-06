#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0xF0;
		}default:{
			return -1;
		}
	}
}

static uint8_t size(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 2;
		}default:{
			return -1;
		}
	}
}

__attribute__((unused)) static uint8_t* decode_instruction(uint16_t argument, MODES mode){
	return generate_opcode_string(size(mode), mode, opcode(mode), argument);
}

Instruction* registerBEQInstruction(){
	Instruction* beq = (Instruction*) malloc(sizeof(Instruction));
	beq->name = "BEQ";
	beq->modes_count = 1;
	beq->modes = (MODES*) malloc(beq->modes_count * sizeof(int));
	beq->modes[0] = RELATIVE;
	beq->opcode = &opcode;
	beq->size = &size;	
	beq->decode_instruction = &decode_instruction;
	return beq;
}

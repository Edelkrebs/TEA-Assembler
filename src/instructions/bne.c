#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0xD0;
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

Instruction* registerBNEInstruction(){
	Instruction* bne = (Instruction*) malloc(sizeof(Instruction));
	bne->name = "BNE";
	bne->modes_count = 1;
	bne->modes = (MODES*) malloc(bne->modes_count * sizeof(int));
	bne->modes[0] = RELATIVE;
	bne->opcode = &opcode;
	bne->size = &size;	
	bne->decode_instruction = &decode_instruction;
	return bne;
}

#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x90;
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

Instruction* registerBCCInstruction(){
	Instruction* bcc = (Instruction*) malloc(sizeof(Instruction));
	bcc->name = "BCC";
	bcc->modes_count = 1;
	bcc->modes = (MODES*) malloc(bcc->modes_count * sizeof(int));
	bcc->modes[0] = RELATIVE;
	bcc->opcode = &opcode;
	bcc->size = &size;	
	bcc->decode_instruction = &decode_instruction;
	return bcc;
}

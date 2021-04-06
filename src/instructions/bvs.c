#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x70;
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

Instruction* registerBVSInstruction(){
	Instruction* bvs = (Instruction*) malloc(sizeof(Instruction));
	bvs->name = "BVS";
	bvs->modes_count = 1;
	bvs->modes = (MODES*) malloc(bvs->modes_count * sizeof(int));
	bvs->modes[0] = RELATIVE;
	bvs->opcode = &opcode;
	bvs->size = &size;	
	bvs->decode_instruction = &decode_instruction;
	return bvs;
}

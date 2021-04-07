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

Instruction* registerBVSInstruction(){
	Instruction* bvs = (Instruction*) malloc(sizeof(Instruction));
	bvs->name = "BVS";
	bvs->modes_count = 1;
	bvs->modes = (MODES*) malloc(bvs->modes_count * sizeof(int));
	bvs->modes[0] = RELATIVE;
	bvs->opcode = &opcode;
	return bvs;
}

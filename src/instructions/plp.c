#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x28;
		}default:{
			return -1;
		}
	}
}

Instruction* registerPLPInstruction(){
	Instruction* plp = (Instruction*) malloc(sizeof(Instruction));
	plp->name = "PLP";
	plp->modes_count = 1;
	plp->modes = (MODES*) malloc(plp->modes_count * sizeof(int));
	plp->modes[0] = IMPLIED;
	plp->opcode = &opcode;
	return plp;
}
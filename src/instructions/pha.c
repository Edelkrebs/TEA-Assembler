#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x48;
		}default:{
			return -1;
		}
	}
}

Instruction* registerPHAInstruction(){
	Instruction* pha = (Instruction*) malloc(sizeof(Instruction));
	pha->name = "PHA";
	pha->modes_count = 1;
	pha->modes = (MODES*) malloc(pha->modes_count * sizeof(int));
	pha->modes[0] = IMPLIED;
	pha->opcode = &opcode;
	return pha;
}
#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x88;
		}default:{
			return -1;
		}
	}
}

Instruction* registerDEYInstruction(){
	Instruction* dey = (Instruction*) malloc(sizeof(Instruction));
	dey->name = "DEY";
	dey->modes_count = 1;
	dey->modes = (MODES*) malloc(dey->modes_count * sizeof(int));
	dey->modes[0] = IMPLIED;
	dey->opcode = &opcode;
	return dey;
}
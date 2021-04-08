#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x60;
		}default:{
			return -1;
		}
	}
}

Instruction* registerRTSInstruction(){
	Instruction* rts = (Instruction*) malloc(sizeof(Instruction));
	rts->name = "RTS";
	rts->modes_count = 1;
	rts->modes = (MODES*) malloc(rts->modes_count * sizeof(int));
	rts->modes[0] = IMPLIED;
	rts->opcode = &opcode;
	return rts;
}
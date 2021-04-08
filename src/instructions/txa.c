#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xBA;
		}default:{
			return -1;
		}
	}
}

Instruction* registerTXAInstruction(){
	Instruction* txa = (Instruction*) malloc(sizeof(Instruction));
	txa->name = "TXA";
	txa->modes_count = 1;
	txa->modes = (MODES*) malloc(txa->modes_count * sizeof(int));
	txa->modes[0] = IMPLIED;
	txa->opcode = &opcode;
	return txa;
}
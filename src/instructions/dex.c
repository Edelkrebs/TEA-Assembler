#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xCA;
		}default:{
			return -1;
		}
	}
}

Instruction* registerDEXInstruction(){
	Instruction* dex = (Instruction*) malloc(sizeof(Instruction));
	dex->name = "DEX";
	dex->modes_count = 1;
	dex->modes = (MODES*) malloc(dex->modes_count * sizeof(int));
	dex->modes[0] = IMPLIED;
	dex->opcode = &opcode;
	return dex;
}
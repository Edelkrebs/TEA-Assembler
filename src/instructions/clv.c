#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xB8;
		}default:{
			return -1;
		}
	}
}

Instruction* registerCLVInstruction(){
	Instruction* clv = (Instruction*) malloc(sizeof(Instruction));
	clv->name = "CLV";
	clv->modes_count = 1;
	clv->modes = (MODES*) malloc(clv->modes_count * sizeof(int));
	clv->modes[0] = IMPLIED;
	clv->opcode = &opcode;
	return clv;
}

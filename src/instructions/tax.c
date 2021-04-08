#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xAA;
		}default:{
			return -1;
		}
	}
}

Instruction* registerTAXInstruction(){
	Instruction* tax = (Instruction*) malloc(sizeof(Instruction));
	tax->name = "TAX";
	tax->modes_count = 1;
	tax->modes = (MODES*) malloc(tax->modes_count * sizeof(int));
	tax->modes[0] = IMPLIED;
	tax->opcode = &opcode;
	return tax;
}
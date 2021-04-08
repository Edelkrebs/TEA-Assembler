#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x40;
		}default:{
			return -1;
		}
	}
}

Instruction* registerRTIInstruction(){
	Instruction* rti = (Instruction*) malloc(sizeof(Instruction));
	rti->name = "RTI";
	rti->modes_count = 1;
	rti->modes = (MODES*) malloc(rti->modes_count * sizeof(int));
	rti->modes[0] = IMPLIED;
	rti->opcode = &opcode;
	return rti;
}
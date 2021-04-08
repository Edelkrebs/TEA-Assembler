#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x78;
		}default:{
			return -1;
		}
	}
}

Instruction* registerSEIInstruction(){
	Instruction* sei = (Instruction*) malloc(sizeof(Instruction));
	sei->name = "SEI";
	sei->modes_count = 1;
	sei->modes = (MODES*) malloc(sei->modes_count * sizeof(int));
	sei->modes[0] = IMPLIED;
	sei->opcode = &opcode;
	return sei;
}

#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0x09;
		}case ZERO_PAGE: {
			return 0x05;
		}case ZERO_PAGE_X: {
			return 0x15;
		}case ABSOLUTE: {
			return 0x0D;
		}case ABSOLUTE_X: {
			return 0x1D;
		}case ABSOLUTE_Y: {
			return 0x19;
		}case INDIRECT_X: {
			return 0x01;
		}case INDIRECT_Y: {
			return 0x11;
		}default:{
			return -1;
		}
	}
}

Instruction* registerORAInstruction(){
	Instruction* ora = (Instruction*) malloc(sizeof(Instruction));
	ora->name = "ORA";
	ora->modes_count = 8;
	ora->modes = (MODES*) malloc(ora->modes_count * sizeof(int));
	ora->modes[0] = IMMEDIATE;
	ora->modes[1] = ZERO_PAGE;
	ora->modes[2] = ZERO_PAGE_X;
	ora->modes[3] = ABSOLUTE;
	ora->modes[4] = ABSOLUTE_X;
	ora->modes[5] = ABSOLUTE_Y;
	ora->modes[6] = INDIRECT_X;
	ora->modes[7] = INDIRECT_Y;
	ora->opcode = &opcode;
	return ora;
}
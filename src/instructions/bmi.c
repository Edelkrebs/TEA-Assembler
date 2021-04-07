#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x30;
		}default:{
			return -1;
		}
	}
}

Instruction* registerBMIInstruction(){
	Instruction* bmi = (Instruction*) malloc(sizeof(Instruction));
	bmi->name = "BMI";
	bmi->modes_count = 1;
	bmi->modes = (MODES*) malloc(bmi->modes_count * sizeof(int));
	bmi->modes[0] = RELATIVE;
	bmi->opcode = &opcode;
	return bmi;
}

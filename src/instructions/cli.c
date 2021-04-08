#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x58;
		}default:{
			return -1;
		}
	}
}

Instruction* registerCLIInstruction(){
	Instruction* cli = (Instruction*) malloc(sizeof(Instruction));
	cli->name = "CLI";
	cli->modes_count = 1;
	cli->modes = (MODES*) malloc(cli->modes_count * sizeof(int));
	cli->modes[0] = IMPLIED;
	cli->opcode = &opcode;
	return cli;
}

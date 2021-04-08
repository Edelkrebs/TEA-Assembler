#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x9A;
		}default:{
			return -1;
		}
	}
}

Instruction* registerTXSInstruction(){
	Instruction* txs = (Instruction*) malloc(sizeof(Instruction));
	txs->name = "TXS";
	txs->modes_count = 1;
	txs->modes = (MODES*) malloc(txs->modes_count * sizeof(int));
	txs->modes[0] = IMPLIED;
	txs->opcode = &opcode;
	return txs;
}
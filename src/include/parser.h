#ifndef __PARSER_H
#define __PARSER_H

#include <stdint.h>

#include <instruction/instruction.h>

MODES getMode(const char* argument);
uint8_t* parse_line(const char* line);

#endif
#include <fileio.h>
#include <stdio.h>

void readFileToBuffer(const char* file_name){
	FILE* file = fopen(file_name, "r");

	char c;
	int line_index = 0;
	int index = 0; 											// Read the file into a 2D Buffer
	for(index = 0; c != EOF; index++){ 		// With each line being represented
		c = fgetc(file);
		if(c == '\n' || c == '\0'){ 						// By a line index and each position
			file_buffer[line_index][index] = '\0'; 		// In that line being represented by
			line_index ++; 									// A index.
			index = 0; 										// If it hits 0, null terminate the line
			continue; 										// And begin reading the next one.
		} 													
		file_buffer[line_index][index] = c;										 			
	}
}
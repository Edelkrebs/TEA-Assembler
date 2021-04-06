#include <fileio.h>
#include <stdio.h>

void readFileToBuffer(const char* file_name){
	FILE* file = fopen(file_name, "r");

	char c;
	int line_index = 0;
	int index = 0;
	for(index = 0; c != EOF; index++){ 						// Read the file into a 2D Buffer
		c = fgetc(file); 									// With each line being represented
		if(c == '\n'){ 										// By a line index and each position
			file_buffer[line_index][index] = c; 			// In that line being represented by
			file_buffer[line_index][index + 1] = '\0'; 		// A index.
			line_index ++; 									// If it hits 0, null terminate the line
			index = 0; 										// And begin reading the next one.
		}
		file_buffer[line_index][index] = c;
	}

	file_buffer[line_index][index + 1] = '\0'; 				// Null terminate the last line.
}
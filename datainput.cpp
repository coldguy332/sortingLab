#include "datainput.h"
 
void create_array() {
	std::ifstream in_file;
	in_file.open("file1.csv");
	int index = line_counter(in_file);
	std::cout << index; 
}

int line_counter(std::ifstream& in_file) {
	std::string temp_line;
	int counter = 0;

	getline(in_file, temp_line);
	while (!in_file.eof()) {
		getline(in_file,temp_line);
		counter++;
	}
	in_file.clear();
	in_file.seekg(0);
	return counter;
}
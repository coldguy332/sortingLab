#include "datainput.h"
 
void create_array() {
	std::ifstream in_file;
	in_file.open("smallfile.csv");
	int index = line_counter(in_file);
	Country *arr_one = new Country[index];
	array_filler(in_file,arr_one,index);

}

void array_filler(std::ifstream& in_file, Country *arr, int index) {
	std::string temp_line; 

	std::string temp_name;
	std::string temp_code;
	std::string temp_calling;
	std::string temp_year;
	std::string temp_emissions;
	std::string temp_population;
	std::string temp_area;
	std::string temp_percent;
	std::string temp_density;


	getline(in_file, temp_line); //index is independent from first line of csv
	std::cout << temp_line << std::endl;

	for (int i = 0; i < index; i++) {
		getline(in_file,temp_line);
		std::stringstream ss; //dont understand why, but this has to be in the loop rather than outside
		ss.str(temp_line);

		getline(ss, temp_name, ',');
		getline(ss, temp_code, ',');
		getline(ss, temp_calling, ',');
		getline(ss, temp_year, ',');
		getline(ss, temp_emissions, ',');
		getline(ss, temp_population, ',');
		getline(ss, temp_area, ',');
		getline(ss, temp_percent, ',');
		getline(ss, temp_density);

		/*
		arr[i] = Country(temp_name,temp_code,temp_calling, stoi(temp_year), stoi(temp_emissions),
			stoi(temp_population),stoi(temp_area),temp_percent,temp_density);
		*/

	}

	in_file.close();
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
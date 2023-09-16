#include "datainput.h"
 
void create_array() {
	std::ifstream in_file;

	//Creates array of countries from smaller csv file
	in_file.open("smallfile.csv");
	int index = line_counter(in_file);
	Country *arr_one = new Country[index];
	array_filler(in_file,arr_one,index);

	//Creates array of countries from bigger of csv file
	in_file.open("bigfile.csv");
	int index = line_counter(in_file);
	Country *arr_two = new Country[index];
	array_filler(in_file,arr_two,index);

}

/**
 * Function parses through csv file to fill in data members of Country objects in array
**/

void array_filler(std::ifstream& in_file, Country *arr, int index) {
	std::string temp_line; //temp string to store one row of data from csv file

	//temp strings that will be used to store data from reading csv
	//temp strings will be used as paramater in country object constructor
	std::string temp_name;
	std::string temp_code;f
	std::string temp_calling;
	std::string temp_year;
	std::string temp_emissions;
	std::string temp_population;
	std::string temp_area;
	std::string temp_percent;
	std::string temp_density;

	//First line of csv file doesn't actually store data, needs to be skipped
	getline(in_file, temp_line); 

	//For loop which will parse through csv file
	for (int i = 0; i < index; i++) {
		getline(in_file,temp_line); //For each pass, program will take one row of csv file and store in temp line
		std::stringstream ss; //Stringstream utilized to parse through the row of information
		ss.str(temp_line); //Stringstream copies all information from the temp line

		//Stringstream will store information in temp strings, comma represents where data ends for one value
		getline(ss, temp_name, ',');
		getline(ss, temp_code, ',');
		getline(ss, temp_calling, ',');
		getline(ss, temp_year, ',');
		getline(ss, temp_emissions, ',');
		getline(ss, temp_population, ',');
		getline(ss, temp_area, ',');
		getline(ss, temp_percent, ',');
		getline(ss, temp_density);

		//Country object created, utilizing temp strings for constructor
		arr[i] = Country(temp_name,temp_code,temp_calling, temp_year, temp_emissions,
			temp_population,temp_area,temp_percent,temp_density);
	}
	//Once the end of file is reached, program returns to the top of the page
	//NECESSARY or program will try reading from the bottom of the page when creating country arrays
	//Because the program allows user to try more than once, this will be necessary
	in_file.clear();
	in_file.seekg(0);
	//File closes
	in_file.close();
}

/**
 * Although not necessary for this project (could be hardcoded)
 * Function counts how many rows are in the csv file
 * This will be used as an index for the arrays being created
**/
int line_counter(std::ifstream& in_file) {
	//temp string for row of data to be stored in
	std::string temp_line;
	int index = 0; //Index that increments for every row counted

	getline(in_file, temp_line); //First row of csv file unnecessary, and therefore passed through

	while (!in_file.eof()) { //While loop functions until the end of the csv file
		getline(in_file,temp_line); //Cycles through the rows one by one
		index++; //index number increments
	}

	//Once the end of file is reached, program returns to the top of the page
	//NECESSARY or program will try reading from the bottom of the page when creating country arrays
	in_file.clear();
	in_file.seekg(0);

	return index; //Returns index number
}
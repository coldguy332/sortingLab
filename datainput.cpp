#include "datainput.h"
 
void create_array() {
	std::ifstream in_file;

	//Creates array of countries from smaller csv file
	in_file.open("smallfile.csv");
	int index_one = line_counter(in_file);
	Country *arr_one = new Country[index_one];
	array_filler(in_file,arr_one,index_one);

	//Creates array of countries from bigger of csv file
	in_file.open("bigfile.csv");
	int index_two = line_counter(in_file);
	Country *arr_two = new Country[index_two];
	array_filler(in_file,arr_two,index_two);

	choosing_algorithm(arr_one, arr_two,index_one,index_two);
	
}

/**
 * Function parses through csv file to fill in data members of Country objects in array
**/
void array_filler(std::ifstream& in_file, Country *arr, int index) {
	std::string temp_line; //temp string to store one row of data from csv file

	//temp strings that will be used to store data from reading csv
	//temp strings will be used as paramater in country object constructor
	std::string temp_name;
	std::string temp_code;
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
		//Necessary function that is able to parse through quotation marks
		quoted_field_code(ss,temp_calling);
		getline(ss, temp_year, ',');
		getline(ss, temp_emissions, ',');
		getline(ss, temp_population, ',');
		getline(ss, temp_area, ',');
		getline(ss, temp_percent, ',');
		//Necessary function that is able to parse through quotation marks
		quoted_field_density(ss,temp_density);
		 
		//Converts any "empty density strings" into actual empty density strings
		density_check(temp_density);

		comma_remover(temp_calling);
		dash_remover(temp_calling);
		comma_remover(temp_density);
		

		//Converts any empty values into a "-1" which symbolizes an unknown
		unknown_checker(temp_name,temp_code,temp_calling,temp_year,temp_emissions,temp_population,temp_area,temp_percent,temp_density);

		//Country object created, utilizing temp strings for constructor
		arr[i] = Country(temp_name,temp_code,stoi(temp_calling), stoi(temp_year), stoul(temp_emissions),
			stoul(temp_population),stoi(temp_area),stod(temp_percent),stoi(temp_density)); 
		
	}
	//Once the end of file is reached, program returns to the top of the page
	//NECESSARY or program will try reading from the bottom of the page when creating country arrays
	//Because the program allows user to try more than once, this will be necessary

	in_file.clear(); //Resets error flags on a stream such as end of file
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
	
	//File closes
	in_file.close();
}



/**
 * Converts any empty strings into "-1" which symbolizes an unknown
**/
void unknown_checker(std::string& temp_name, std::string& temp_code, std::string& temp_calling, std::string& temp_year ,
			std::string& temp_emissions, std::string& temp_population, std::string& temp_area, std::string& temp_percent, std::string& temp_density) {
	if (temp_name.empty()) {
		temp_name = "-1";
	}
	if (temp_code.empty()) {
		temp_code = "-1";
	}
	if (temp_calling.empty()) {
		temp_calling = "-1";
	}
	if (temp_year.empty()) {
		temp_year = "-1" ;
		//all integer data members with a -1 will signify an unknown
	}
	if (temp_emissions.empty()) {
		temp_emissions = "-1";
	}
	if (temp_population.empty()) {
		temp_population = "-1" ;
	}
	if (temp_area.empty()) {
		temp_area = "-1";
	}
	if (temp_percent.empty()) {
		temp_percent = "-1.0";
	}
	if (temp_density.empty()) {
		temp_density = "-1";
	}
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

/**
 * PRACTICALLY RIPPED FROM CHAT GPT
 * PLZ CITE THE ALL GLORIOUS GPT
*/
void quoted_field_code(std::stringstream& ss, std::string& temp_string){
	if (ss.peek() == '"') {  //program looks to see if quotation mark exists, doesn't actually "collect" it
		ss.ignore(); //If quote does exist, string stream will now pass over the first quote
		getline(ss,temp_string,'"'); //Reads until the next quotation mark
		ss.ignore(); //Final quote is ignored
	}
	else {
		getline(ss, temp_string, ',');
	}
}
void quoted_field_density(std::stringstream& ss, std::string& temp_string) {
	if (ss.peek() == '"') {  //program looks to see if quotation mark exists, doesn't actually "collect" it
		ss.ignore(); //If quote does exist, string stream will now pass over the first quote
		getline(ss,temp_string,'/'); //Reads until the the slash
		ss.ignore(); //Final quote is ignored
	}
	else {
		getline(ss, temp_string, '/');
	}

}

/**
 * This function checks if the temp_density that was parsed through is an empty string or not
 * Issue: Windows and Linux has differences in reading CSV files
 * Ideally this code would work on windows without this function but not on linux
 * Without this function on linux, temp_density looks like an empty string even though it's not (returns a carriage return on linux)
 * @param density //Passing by reference of temp_density
 * @https://stackoverflow.com/questions/4081750/difference-in-reading-csv-file-in-unix-system-windows-system
**/
void density_check(std::string& density){
	std::stringstream dens(density); //Sets stringstream to the temp_density string
	density = ""; //Sets temp_destiny string to an empty string
	dens >> density; //Density stores whatever was in stringstream
}

/**
 * Removes dashes from code
 * @param density Temp density from parsing strings
 * @https://www.tutorialspoint.com/how-to-remove-certain-characters-from-a-string-in-cplusplus#:~:text=In%20C%2B%2B%20we%20can,character%20that%20will%20be%20removed.
**/
void comma_remover(std::string& temp_string) {
	temp_string.erase(std::remove(temp_string.begin(),temp_string.end(),','),temp_string.end()); 
	//Remove searches for all occurences of '-' between the beginning and end of density string and moves them to the end
	//.erase erases the '-'
}

void dash_remover(std::string& temp_string) {
	temp_string.erase(std::remove(temp_string.begin(),temp_string.end(),'-'),temp_string.end()); 
	//Remove searches for all occurences of '-' between the beginning and end of density string and moves them to the end
	//.erase erases the '-'
}
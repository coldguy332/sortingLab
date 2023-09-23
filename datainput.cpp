#include "datainput.h"

/**
 * Creates two arrays of Country objects
**/
void create_array() {
	std::ifstream in_file; //Creating an ifstream object to read csv file

	//Creates array of countries from smaller csv file
	in_file.open("smallfile.csv"); //Opening smaller of two csv files
	int index_one = line_counter(in_file); //Function counts number of lines in csv and stores it
	Country *arr_one = new Country[index_one]; //Creating actual array
	array_filler(in_file,arr_one,index_one); //Calls function that fills array with country objects

	//Creates array of countries from bigger of csv file
	in_file.open("bigfile.csv");
	int index_two = line_counter(in_file);
	Country *arr_two = new Country[index_two];
	array_filler(in_file,arr_two,index_two);

	choosing_algorithm(arr_one, arr_two,index_one,index_two); //Calls function from prompts.cpp/h
	//Function will give user option to choose between sorting algorithms
	
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

		comma_remover(temp_calling); //Removes commas in data values 
		dash_remover(temp_calling); //Removes dashes in data values
		comma_remover(temp_density);//Removes commas in data values 
	
		
		//Any values with an empty string will have a value of "-1",our symbol for unknown
		unknown_checker(temp_name,temp_code,temp_calling,temp_year,temp_emissions,temp_population,temp_area,temp_percent,temp_density);

		//Country object created, utilizing temp strings for constructor
		arr[i] = Country(temp_name,temp_code,stoi(temp_calling), stoi(temp_year), stoul(temp_emissions),
			stoul(temp_population),stoi(temp_area),stod(temp_percent),stoi(temp_density)); 
	
	}

	//Once the end of file is reached, program returns to the top of the page
	//NECESSARY or program will try reading from the bottom of the page when creating country arrays
	//Because the program allows user to try more than once, this will be necessary

	in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file
	
	//File closes
	in_file.close();
}



/**
 * Converts any empty strings into "-1" which symbolizes an unknown
**/
void unknown_checker(std::string& temp_name, std::string& temp_code, std::string& temp_calling, std::string& temp_year ,
			std::string& temp_emissions, std::string& temp_population, std::string& temp_area, std::string& temp_percent, std::string& temp_density) {
	if (temp_name.empty()) {  //Empty tests if string is empty
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
 * @param in_file ifstream object
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
	in_file.clear(); //Resets error flags on a stream such as EOF
	in_file.seekg(0);//sets position of next character to be read back to beginning of file

	return index; //Returns index number
}

/**
 * Function that parses through data values that have quotation marks
 * @param ss stringstream passed by reference
 * @param temp_string string that will store data value passed by reference
*/
void quoted_field_code(std::stringstream& ss, std::string& temp_string){
	if (ss.peek() == '"') {  //program looks to see if quotation mark exists, doesn't actually "collect" it
		ss.ignore(); //If quote does exist, string stream will now pass over the first quote
		getline(ss,temp_string,'"'); //Reads until the next quotation mark
		ss.ignore(); //Final quote is ignored
	}
	else {
		getline(ss, temp_string, ','); //If no quotation marks, just parses regularly
	}
}

/**
 * Virtually same function as before but changed slightly for getting density value
 * @param ss stringstream passed by reference
 * @param temp_string string that will store data value passed by 
**/
void quoted_field_density(std::stringstream& ss, std::string& temp_string) {
	if (ss.peek() == '"') {  //program looks to see if quotation mark exists, doesn't actually "collect" it
		ss.ignore(); //If quote does exist, string stream will now pass over the first quote
		getline(ss,temp_string,'/'); //Reads until the the slash
		ss.ignore(); //Final quote is ignored
	}
	else {
		getline(ss, temp_string, '/'); //Parses value until slash (in unit /km2)
		//Decided to disregard units as comparing strings ended up being virtually impossible
		//Decided to switch to int data member and you cant stoi() with the units
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
	/*Originally, temp_density had a value of a carriage return if there was no value
	As a result, it showed up blank but wasnt "empty"
	Now if there was any value in the temp_density before the final result would be
	temp_density += ""
	So now, temp_density will either show up as a value or an actual empty string
	*/ 
}

/**
 * Removes commas from code
 * requires algorithm library
 * @param density Temp density from parsing strings
 * @https://www.tutorialspoint.com/how-to-remove-certain-characters-from-a-string-in-cplusplus#:~:text=In%20C%2B%2B%20we%20can,character%20that%20will%20be%20removed.
**/
void comma_remover(std::string& temp_string) {
	temp_string.erase(std::remove(temp_string.begin(),temp_string.end(),','),temp_string.end()); 
	//Remove searches for all occurences of ',' between the beginning and end of string and shifts them 
	//.erase erases the ','
}

/**
 * Removes dashes from code
 * requires algorithm library
 * @param density Temp density from parsing strings
 * @https://www.tutorialspoint.com/how-to-remove-certain-characters-from-a-string-in-cplusplus#:~:text=In%20C%2B%2B%20we%20can,character%20that%20will%20be%20removed.
**/
void dash_remover(std::string& temp_string) {
	temp_string.erase(std::remove(temp_string.begin(),temp_string.end(),'-'),temp_string.end()); 
	////Remove searches for all occurences of '-' between the beginning and end of string and shifts them 
	//.erase erases the '-'
}
#include "save.h"

/**
 * Outputs country array objects in a csv format
 * @param arr_one Country array one
 * @param arr_two Country array two
 * @param size_one Size of array index one
 * @param size_two Size of array index two
**/
void output_to_file(Country* arr_one, Country* arr_two, int size_one, int size_two) {
	//strings that will eventually hold the names of files to be outputted to
	std::string filename_one;
	std::string filename_two;

	std::cout << std::endl << "Enter the name of the first file you want to create:" ;
	std::cin >> filename_one;
	std::cout << std::endl << "Enter the name of the second file you want to create: ";
	std::cin >> filename_two;

	std::ofstream off_file; //Creating ofstream object

	off_file.open(filename_one + ".csv");//Creating a new file and outputting criterias
	off_file << "Country" << "," << "Code" << "," << "Calling Code" << "," << "Year" << "," << "CO2 emissions" << ","
	         << "Population" << "," << "Area" << "," << "% of world"  << ","<< "Density" << std::endl;
	
	for (int i = 0; i < size_one; i++) { //Outputting data member values into file
		arr_one[i].offload_data(off_file);//Function outputting data members from country.cpp
		off_file << std::endl;
	}
	off_file.close(); //Closing file one

	off_file.open(filename_two +".csv"); //Creating a new file and outputting criterias
	off_file << "Country" << "," << "Code" << "," << "Calling Code" << "," << "Year" << "," << "CO2 emissions" << ","
	         << "Population" << "," << "Area" << "," << "% of world"  << ","<< "Density" << std::endl;
	
	for (int i = 0; i < size_two; i++) { //Outputting data member values into file
		arr_two[i].offload_data(off_file); //Function outputting data members from country.cpp
		off_file << std::endl;
	}
	off_file.close(); //Closing file two

	std::cout << std::endl << "Files have been saved" << std::endl;	
}
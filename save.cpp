#include "save.h"

void output_to_file(Country* arr_one, Country* arr_two, int index_one, int index_two) {
	std::string filename_one;
	std::string filename_two;

	std::cout << std::endl << "Enter the name of the first file you want to create:" ;
	std::cin >> filename_one;
	std::cout << std::endl << "Enter the name of the second file you want to create: ";
	std::cin >> filename_two;

	std::ofstream off_file;

	off_file.open(filename_one + ".csv");
	off_file << "Country" << "," << "Code" << "," << "Calling Code" << "," << "Year" << "," << "CO2 emissions" << ","
	         << "Population" << "," << "Area" << "," << "% of world"  << ","<< "Density" << std::endl;
	for (int i = 0; i < index_one; i++) {
		arr_one[i].offload_data(off_file);
		off_file << std::endl;
	}
	off_file.close();

	off_file.open(filename_two +".csv"); 
	off_file << "Country" << "," << "Code" << "," << "Calling Code" << "," << "Year" << "," << "CO2 emissions" << ","
	         << "Population" << "," << "Area" << "," << "% of world"  << ","<< "Density" << std::endl;
	for (int i = 0; i < index_two; i++) {
		arr_two[i].offload_data(off_file);
		off_file << std::endl;
	}
	off_file.close();

	std::cout << std::endl << "Files have been saved" << std::endl;	
}
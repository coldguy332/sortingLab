#include "prompts.h"

void welcome_prompt() {
	std::cout << "Hello. This program sorts various characteristics of countries that contribute to CO2 emissions" << std::endl;
	std::cout << "Would you like to continue(Y/n):" ;
	char choice;
	std::cin >> choice;
	if (choice == 'N' || choice == 'n') {
		exit(0);
	} 
	if (choice == 'Y' || choice == 'y') {
		std::cout << std::endl << "Reading from files..." << std::endl;
		create_array();
	}
}

void choosing_algorithm(Country *arr_one, Country *arr_two, int index_one, int index_two) {
	char choice;
	std::cout << "Reading from files completed. Data has been inputed." << std::endl;
	std::cout << "Do you want to " << std::endl 
		<<"A)sort from all algorithms at the same time "<< std::endl 
		<<"B)one random slow and fast algorithm" << std::endl;
	std::cin >> choice;

	if (choice == 'A') {
		all_algos(arr_one, arr_two, index_one, index_two);
	}
	else if (choice == 'B') {
		rand_algos(arr_one, arr_two, index_one, index_two);
	}

}
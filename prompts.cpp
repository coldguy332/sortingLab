#include "prompts.h"

/**
 * Welcomes user to the program
 * Explains what program does
 * User has choice not to use program
**/
void welcome_prompt() {
	std::cout << "Hello. This program sorts various characteristics of countries that contribute to CO2 emissions" << std::endl;
	std::cout << "Would you like to continue(Y/n):" ;
	char choice;
	std::cin >> choice;
	if (choice == 'N' || choice == 'n') {
		exit(0); //Quits program
	} 
	if (choice == 'Y' || choice == 'y') {
		std::cout << std::endl << "Reading from files..." << std::endl;
		create_array(); //Creates two arrays, function from datainput.h
	}
}

/**
 * User given the option to choose all algorithms or one slow and one fast algorithm
 * @param arr_one Country array one
 * @param arr_two Country array two
 * @param size_one Index size for country array one
 * @param size_two Index size for country array two
**/
void choosing_algorithm(Country *arr_one, Country *arr_two, int size_one, int size_two) {
	char choice;
	std::cout << "Reading from files completed. Data has been inputed." << std::endl;
	std::cout << "Do you want to " << std::endl 
		<<"A)sort from all algorithms at the same time "<< std::endl 
		<<"B)one random slow and fast algorithm" << std::endl;
	std::cin >> choice;

	if (choice == 'A' || choice == 'a') {
		all_algos(arr_one, arr_two, size_one, size_two); //Function that utilizes all sort algorithms, from sorter.h
	}
	else if (choice == 'B' || choice == 'b') {
		rand_algos(arr_one, arr_two, size_one, size_two); //Function that utilizes one fast and slow algorithm, from sorter.h
	}

}

/**
 * Allows user to save and quit from program
 * @param arr_one Country array one
 * @param arr_two Country array two
 * @param size_one Index size of array one
 * @param size_two Index size of array two
**/
void save_and_quit(Country* arr_one, Country *arr_two,int size_one,int size_two) {
	char choice;
	std::cout << "Would you like to save your sorted lists?(Y/n):" ;
	std::cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		output_to_file(arr_one,arr_two, size_one, size_two); //Calls function that will output to a csv, from save.h
	}
	//Deletes array or memory leak can occur
	delete[] arr_one;
	delete[] arr_two;

	std::cout << "Would you like to " << std::endl << "A)Quit the program" << std::endl 
			  << "B)Re-use the program" << std::endl;
	std::cin >> choice;
	if (choice == 'A' || choice == 'a') {
		exit(0); //Exits program
	}
	if (choice == 'B' || choice == 'b') {
		welcome_prompt(); //Re-runs the program
	}
	
}
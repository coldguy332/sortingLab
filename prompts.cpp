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
		create_array();
	}
}
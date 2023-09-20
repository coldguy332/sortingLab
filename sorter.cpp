#include "sorter.h"

void all_algos(Country *arr_one, Country *arr_two,int index_one, int index_two) {
	int choice_one;
	int choice_two;
	sort_criteria(choice_one, choice_two);
	merge_sort(arr_one,0,index_one-1,choice_one);
	for (int i = 0; i < index_one; i++) {
		std::cout << i+2 << ")" << arr_one[i].get_emissions() << std::endl;
	}
}

void rand_algos(Country *arr_one, Country *arr_two,int index_one, int index_two) {
	int choice_one;
	int choice_two;
	sort_criteria(choice_one, choice_two);
}

void sort_criteria(int& choice_one, int& choice_two) {
	std::cout << "This program allows you to sort 9 different criterias. Two of these criterias can be sorted " 
				  "at the same time." << std::endl;
	std::cout << "Here are the crierias:" << std::endl;
	std::cout << "1) Country Name" << std::endl << "2) Code" << std::endl << "3) Calling Code" << std::endl
	          << "4) Year" << std::endl << "5) Emissions" << std::endl << "6) Population" << std::endl
	          << "7) Area" << std::endl << "8) % of the world" << std::endl << "9) Density (KM^2)" << std::endl; 
	std::cout << "Please enter first choice of criteria:" ;
	std::cin >> choice_one;
	std::cout << "Please enter second choice of crieria:" ;
	std::cin >> choice_two;
	std::cout << std::endl; 
}
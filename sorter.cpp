#include "sorter.h"

using namespace std::chrono;

void all_algos(Country *arr_one, Country *arr_two,int index_one, int index_two) {
	int choice_one;
	int choice_two;
	sort_criteria(choice_one, choice_two);
	//launch_bubble(arr_one, index_one,choice_one);
	//launch_selection(arr_one, index_one,choice_one);
	//launch_insertion(arr_one, index_one,choice_one);
	launch_merge(arr_one,0,index_one,choice_one);

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

void launch_bubble(Country* arr, int index, int choice) {
	long double time = 0.0;
	for (int i = 0; i < 5; i++) {
		Country *copy = new Country[index];
		for (int j = 0; j < index; j++) {
			copy[j] = arr[j];
		}
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		new_bubblesort(copy,index,choice);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time += duration_cast<duration<double>>(t2 - t1).count();
		delete[] copy;
	}
	time = time / 5;
	std::cout << time << std::endl;
}

void launch_selection(Country* arr, int index, int choice) {
	long double time = 0.0;
	for (int i = 0; i < 5; i++) {
		Country *copy = new Country[index];
		for (int j = 0; j < index; j++) {
			copy[j] = arr[j];
		}
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		selection_sort(copy,index,choice);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time += duration_cast<duration<double>>(t2 - t1).count();
		delete[] copy;
	}
	time = time / 5;
	std::cout << time << std::endl;
}

void launch_insertion(Country* arr, int index, int choice) {
	long double time = 0.0;
	for (int i = 0; i < 5; i++) {
		Country *copy = new Country[index];
		for (int j = 0; j < index; j++) {
			copy[j] = arr[j];
		}
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		insertion_sort(copy,index,choice);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time += duration_cast<duration<double>>(t2 - t1).count();
		delete[] copy;
	}
	time = time / 5;
	std::cout << time << std::endl;
}

void launch_merge(Country *arr, int from, int to,int choice) {
	long double time = 0.0;
	for (int i = 0; i < 5; i++) {
		Country *copy = new Country[to];
		for (int i = 0; i < to; i++) {
			copy[i] = arr[i];
		}
		std::cout << "Test 1" << std::endl;

		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		merge_sort(copy,0,to,choice);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time += duration_cast<duration<double>>(t2 - t1).count();
		std::cout << "Test 2" << std::endl;
		delete[] copy;
	}
	std::cout << "Test 2" << std::endl;
	time = time / 5;
	std::cout << time << std::endl;
}

std::string get_criteria(int choice){
	switch (choice) {
        case 1: 
            return "Country Name";
            break;
        case 2:
            return "Code";
            break;
        case 3:
            return "Calling Code";
            break;
        case 4:
            return "Year";
            break;
        case 5:
            return "Emissions";
            break;
        case 6:
            return "Population";
            break;
        case 7:
            return "Area";
            break;
        case 8:
            return "Percent";
            break;
        case 9:
            return "Density";
            break;
        default:
        	return "";
        	break;
    }
}


#include "sorter.h"

using namespace std::chrono;

void all_algos(Country *arr_one, Country *arr_two,int index_one, int index_two) {
	int choice_one;
	int choice_two;
	sort_criteria(choice_one, choice_two);
	display_borders(choice_one);

	launch_smallfile(arr_one,index_one,choice_one,choice_two);
	launch_bigfile(arr_two,index_two,choice_one,choice_two);

}

void rand_algos(Country *arr_one, Country *arr_two,int index_one, int index_two) {
	int choice_one;
	int choice_two;
	sort_criteria(choice_one, choice_two);
	display_borders(choice_one);

	choose_rand_alg(arr_one,index_one,choice_one,choice_two);
	//choose_rand_alg(arr_two,index_two,choice_one,choice_two);

	output_data(arr_one,index_one,choice_one,choice_two);
	//output_data(arr_two,index_two,choice_one,choice_two);


	//Merge sorts original array by choices to be passed into possible save file
	merge_sort(arr_one,0,index_one-1,choice_one);
	merge_sort(arr_two,0,index_two-1,choice_two);
	save_and_quit(arr_one, arr_two,index_one,index_two);

	
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

void launch_smallfile(Country *arr_one, int index_one, int choice_one, int choice_two) {
	launch_merge(arr_one,0,index_one-1,choice_one);
	launch_insertion(arr_one, index_one,choice_one);
	launch_bubble(arr_one, index_one,choice_one);
	launch_selection(arr_one, index_one,choice_one);
	
	launch_merge(arr_one,0,index_one-1,choice_two);
	launch_insertion(arr_one, index_one,choice_two);
	launch_bubble(arr_one, index_one,choice_two);
	launch_selection(arr_one, index_one,choice_two);

	
}

void launch_bigfile(Country *arr_two,int index_two,int choice_one, int choice_two) {
	launch_merge(arr_two,0,index_two-1,choice_one);
	launch_insertion(arr_two, index_two,choice_one);
	launch_bubble(arr_two, index_two,choice_one);
	launch_selection(arr_two, index_two,choice_one);
	
	launch_merge(arr_two,0,index_two-1,choice_two);
	launch_insertion(arr_two, index_two,choice_two);
	launch_bubble(arr_two, index_two,choice_two);
	launch_selection(arr_two, index_two,choice_two);
}

void launch_bubble(Country* arr, int index, int choice) {
	long double time = 0.0;
	Country *copy = new Country[index];
	for (int i = 0; i < index; i++) {
			copy[i] = arr[i];
	}
	for (int i = 0; i < 5; i++) {
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		new_bubblesort(arr,index,choice);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time += duration_cast<duration<double>>(t2 - t1).count();		
		for (int i = 0; i < index; i++) {
			arr[i] = copy[i];
		}
	}
	delete[] copy;
	time = time / 5;
	std::string criteria = get_criteria(choice);
	std::cout << std::setw(20) << std::left << criteria;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::left << time;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << "Bubble Sort";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << already_sorted_check(choice) << std::endl;

}

void launch_selection(Country* arr, int index, int choice) {
	long double time = 0.0;
	Country *copy = new Country[index];
	for (int i = 0; i < index; i++) {
			copy[i] = arr[i];
	}
	for (int i = 0; i < 5; i++) {
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		selection_sort(arr,index,choice);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time += duration_cast<duration<double>>(t2 - t1).count();
		for (int i = 0; i < index; i++) {
			arr[i] = copy[i];
		}
	}
	delete[] copy;
	time = time / 5;
	std::string criteria = get_criteria(choice);
	std::cout << std::setw(20) << std::left << criteria;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::left << time;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << "Selection Sort";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << already_sorted_check(choice) << std::endl;
}

void launch_insertion(Country* arr, int index, int choice) {
	long double time = 0.0;
	Country *copy = new Country[index];
	for (int i = 0; i < index; i++) {
			copy[i] = arr[i];
	}
	for (int i = 0; i < 5; i++) {
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		insertion_sort(arr,index,choice);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time += duration_cast<duration<double>>(t2 - t1).count();
		for (int i = 0; i < index; i++) {
			arr[i] = copy[i];
		}
	}
	delete[] copy;
	time = time / 5;
	std::string criteria = get_criteria(choice);
	std::cout << std::setw(20) << std::left << criteria;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::left << time;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << "Insertion Sort";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << already_sorted_check(choice) << std::endl;
}

void launch_merge(Country *arr, int from, int to,int choice) {
	long double time = 0.0;
	Country *copy = new Country[to];
	for (int i = 0; i < to; i++) {
			copy[i] = arr[i];
	}
	for (int i = 0; i < 5; i++) {
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		merge_sort(arr,0,to,choice);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time += duration_cast<duration<double>>(t2 - t1).count();
		for (int i = 0; i < to; i++) {
			arr[i] = copy[i];
		}
	}
	delete[] copy;
	time = time / 5;
	std::string criteria = get_criteria(choice);
	std::cout << std::setw(20) << std::left << criteria;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::left << time;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << "Merge Sort";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << already_sorted_check(choice) << std::endl;
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

void choose_rand_alg(Country *arr, int index, int choice_one, int choice_two) {
	int random = 0;
	for (int i = 0; i < 5; i++) {
		random = rand() % 3 + 1;
	}
	switch (random) {
		case 1:
			launch_selection(arr,index,choice_one);
			launch_selection(arr,index,choice_two);
			break;
		case 2:
			launch_bubble(arr,index,choice_one);
			launch_bubble(arr,index,choice_two);
			break;
		case 3:
			launch_insertion(arr,index,choice_one);
			launch_insertion(arr,index,choice_two);
			break;
	}
	launch_merge(arr,0,index,choice_one);
	launch_merge(arr,0,index,choice_two);
}

std::string already_sorted_check(int choice) {
	if (choice == 1) {
		return "Yes";
	}
	else {
		return "No";
	}
}

void display_borders(int choice) {
	std::string criteria = get_criteria(choice);
	std::cout << std::setw(20) << std::left << "Criteria";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::left << "Time";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << "Algorithm";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << "Already Sorted?" << std::endl;
}

void output_data(Country* arr, int index, int choice_one,int choice_two) {
	std::cout << std::endl;
	std::cout << std::setw(20) << std::left << get_criteria(choice_one);
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << get_criteria(choice_two) << std::endl;
	
	Country *copy = new Country[index];
	Country *copy_a = new Country[index];
	Country *copy_b = new Country[index];
	for (int i = 0; i < index; i++) {
			copy[i] = arr[i];
	}

	merge_sort(arr,0,index,choice_one);
	for (int i = 0; i < index; i++) {
		copy_a[i] = arr[i];
	}
	for (int i = 0; i < index; i++) {
		arr[i] = copy[i];
	}
	merge_sort(arr,0,index,choice_two);
	for (int i = 0; i < index; i++) {
		copy_b[i] = arr[i];
	}
	for (int i = 0; i < index; i++) {
		arr[i] = copy[i];
	}
	std::cout << "Top 50" << std::endl;
	for (int i = 0; i < 50; i++) {
		display_sorted_left(copy_a,i,choice_one);
		std::cout << std::setw(1) << std::left << " ";
		display_sorted_right(copy_b,i,choice_two);
	}
	std::cout << "Bottom 50" << std::endl;
	for (int i = index - 50; i < index; i++) {
		display_sorted_left(copy_a,i,choice_one);
		std::cout << std::setw(1) << std::left << " ";
		display_sorted_right(copy_b,i,choice_two);
	}

	delete[] copy;
	delete[] copy_a;
	delete[] copy_b;
}

void display_sorted_left(Country* arr, int index, int choice) {
	switch (choice) {
		case 1:
			std::cout << std::setw(20) << std::left << arr[index].get_name();
			break;
		case 2:
			std::cout << std::setw(20) << std::left << arr[index].get_code();
			break;
		case 3:
			std::cout << std::setw(20) << std::left << arr[index].get_calling();
			break;
		case 4:
			std::cout << std::setw(20) << std::left << arr[index].get_year();
			break;
		case 5:
			std::cout << std::setw(20) << std::left << arr[index].get_emissions();
			break;
		case 6:
			std::cout << std::setw(20) << std::left << arr[index].get_population();
			break;
		case 7:
			std::cout << std::setw(20) << std::left << arr[index].get_area();
			break;
		case 8:
			std::cout << std::setw(20) << std::left << arr[index].get_percent();
			break;
		case 9:
			std::cout << std::setw(20) << std::left<< arr[index].get_density();
			break;
	}
}

void display_sorted_right(Country* arr, int index, int choice) {
	switch(choice) {
		case 1:
			std::cout << std::setw(20) << std::right << arr[index].get_name() << std::endl;
			break;
		case 2:
			std::cout << std::setw(20) << std::right << arr[index].get_code()<< std::endl;
			break;
		case 3:
			std::cout << std::setw(20) << std::right << arr[index].get_calling()<< std::endl;
			break;
		case 4:
			std::cout << std::setw(20) << std::right << arr[index].get_year()<< std::endl;
			break;
		case 5:
			std::cout << std::setw(20) << std::right << arr[index].get_emissions() << std::endl;
			break;
		case 6:
			std::cout << std::setw(20) << std::right << arr[index].get_population() << std::endl;
			break;
		case 7:
			std::cout << std::setw(20) << std::right << arr[index].get_area() << std::endl;
			break;
		case 8:
			std::cout << std::setw(20) << std::right << arr[index].get_percent() << std::endl;
			break;
		case 9:
			std::cout << std::setw(20) << std::right << arr[index].get_density() << std::endl;
			break;
	}
}


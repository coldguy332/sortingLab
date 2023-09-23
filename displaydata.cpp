#include "displaydata.h"

/**
 * Displays sorting times of sorting algorithms
 * @param criteria name of criteria to be sorted by
 * @param time the time it took for algorithm to sort
 * @param sort_name the name of the sorting algorithm
 * @param choice NUMERICAL value (not name) of criteria to be sorted by
 * @param index Current index of the country array
**/
void display_sort_times(std::string criteria, double time, std::string sort_name, int choice,int index) {
	std::cout << std::setw(20) << std::left << criteria;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::left << time;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << sort_name;
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << already_sorted_check(choice); //outputs if the criteria has already been sorted by default
	std::cout << std::setw(1) << std::right << " ";
	std::cout << std::setw(20) << std::right << big_or_small(index) << std::endl; //Outputs if the file is the small or big one
}

/**
 * Returns the name of criteria choice to be sorted by
 * @param choice numerical number that will be used to determine
 * what the name of the criteria is
**/
std::string get_criteria(int choice) {
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

/**
 * Checks if the criteria has already been sorted by default
 * Only criteria that has been sorted by default is country name
 * As a result, function will return "Yes" or "No" depending if the
 * user chose country name as a criteria or not
**/
std::string already_sorted_check(int choice) {
	if (choice == 1) {
		return "Yes";
	}
	else {
		return "No";
	}
}

/**
 * Displays the non-numerical information of the sorting times
**/
void display_borders(int choice) {
	std::string criteria = get_criteria(choice);
	std::cout << std::setw(20) << std::left << "Criteria";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::left << "Time";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << "Algorithm";
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << "Already Sorted?";
	std::cout << std::setw(1) << std::right << " ";
	std::cout << std::setw(20) << std::right << "Filesize" << std::endl;
}

/**
 * Program will output first 50 sorted items and last 50 sorted items
 * @param arr Country array
 * @param size Size of array index
 * @param choice_one criteria one to be sorted by
 * @param choice_two criteria two to be sorted by
**/
void output_data(Country* arr,int size, int choice_one,int choice_two) {
	//Outputting what criteria names will be sorted
	std::cout << std::endl;
	std::cout << std::setw(20) << std::left << get_criteria(choice_one);
	std::cout << std::setw(1) << std::left << " ";
	std::cout << std::setw(20) << std::right << get_criteria(choice_two) << std::endl;
	
	//a and b will represent array positions
	int a=0;
	int b=0;
	//Creating country array copies
	Country *copy = new Country[size];
	Country *copy_a = new Country[size];
	Country *copy_b = new Country[size];

	copy_array(copy,arr,size); //Backup copy of main array

	merge_sort(arr,0,size-1,choice_one); //Merge sort of main array based on criteria one
	copy_array(copy_a,arr,size); //Copy_a array copies main array after sorting
	
	copy_array(arr,copy,size); //Main array set back to its original form
	
	merge_sort(arr,0,size-1,choice_two); //Merge sort of main array based on criteria two
	copy_array(copy_b,arr,size); //Copy_b array copies main array after sorting
	
	copy_array(arr,copy,size); //Main array set back to its original form
	
	std::cout << "Top 50" << std::endl;
	while (a < size) { //To avoid any unknown numbers, a will increment until there are no more unknowns
		if (copy_a[a].get_data_member(choice_one)) { //bool that tests if data member is = -1 (-1 means unknown)
			a++;
		}
		else {
			break; //Once program detects that the value is not -1, the loop ends
		}
	}

	while (b < size) { //To avoid any unknown numbers, a will increment until there are no more unknowns
		if (copy_b[b].get_data_member(choice_two)) { //bool that tests if data member is = -1 (-1 means unknown)
			b++; 
		}
		else {
			break; //Once program detects that the value is not -1, the loop ends
		}
	}
	
	//int i set equal to position a and increments 50 times
	for (int i = a;i < a + 50; i++) { 
		display_sorted_left(copy_a,i,choice_one); //Displays the data members of sorted criteria one at position i
		std::cout << std::setw(1) << std::left << " ";
		display_sorted_right(copy_b,b,choice_two); //Displays the data members of sorted criteria two at position b
		b++; //b increments with i
	}
	
	std::cout << "Bottom 50" << std::endl;
	//Displays the last 50 data members of sorted criteria one and two
	for (int i = size - 50; i < size; i++) {
		display_sorted_left(copy_a,i,choice_one);
		std::cout << std::setw(1) << std::left << " ";
		display_sorted_right(copy_b,i,choice_two);
	}
	//Deletes copies of arrays to avoid memory leaks
	delete[] copy;
	delete[] copy_a;
	delete[] copy_b;
}

/**
 * Displays one of the country array's information on left side
 * Left side will be array one, right side array two
 * @param arr Country array
 * @param index Current index of the array
 * @param choice criteria which switch case will use to determine what to return
**/
void display_sorted_left(Country* arr,int index, int choice){
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

/**
 * Displays one of the country array's information on right side
 * Left side will be array one, right side array two
 * @param arr Country array
 * @param index Current index of the array
 * @param choice criteria which switch case will use to determine what to return
**/
void display_sorted_right(Country*arr,int index,int choice){
	switch(choice) {
		case 1:
			std::cout << std::setw(20) << std::right << arr[index].get_name() << std::endl;
			break;
		case 2:
			std::cout << std::setw(20) << std::right << arr[index].get_code() << std::endl;
			break;
		case 3:
			std::cout << std::setw(20) << std::right << arr[index].get_calling() << std::endl;
			break;
		case 4:
			std::cout << std::setw(20) << std::right << arr[index].get_year() << std::endl;
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



/**
 * Returns whether the file is big or not
 * One csv is 5000 rows while the other is 59000
 * Will need to be adjusted if csv files were to change
**/
std::string big_or_small(int index) {
	if (index < 6000) {
		return "Small File";
	}
	else {return "Big File";}
}

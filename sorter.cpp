#include "sorter.h"

using namespace std::chrono; //Necessary for timing sorting algorithms

/**
 * Sorts criteria by using all sorting algorithms
 * @param arr_one Country array one
 * @param arr_two Country array two
 * @param size_one Size of array index one
 * @param size_two Size of array index two
**/
void all_algos(Country *arr_one, Country *arr_two,int size_one, int size_two) {
	//Users will choose what criteria to sort with by numerical value
	int choice_one;
	int choice_two;

	sort_criteria(choice_one, choice_two); //Function which prompts user to choose what criteria to sort by
	display_borders(choice_one); //Displays the non-numerical information of the sorting times, from displaydata.cpp

	launch_smallfile(arr_one,size_one,choice_one,choice_two); //Launches 4 algorithms to sort the small csv file
	launch_bigfile(arr_two,size_two,choice_one,choice_two); //Launches 4 algorithms to sort the big csv file

	output_data(arr_one,size_one,choice_one,choice_two); //Outputs sorted data of array one
    output_data(arr_two,size_two,choice_one,choice_two); //Outputs sorted data of array two

    //Permanently sorts array one and two so its data can be saved
    merge_sort(arr_one,0,size_one-1,choice_one); 
	merge_sort(arr_two,0,size_two-1,choice_two);

	save_and_quit(arr_one, arr_two,size_one,size_two);//Function gives user option to save and quit, function from save.cpp

}

/**
 * Sorts criteria by using one slow and fast sorting algorithm
 * @param arr_one Country array one
 * @param arr_two Country array two
 * @param size_one Size of array index one
 * @param size_two Size of array index two
**/
void rand_algos(Country *arr_one, Country *arr_two,int size_one, int size_two) {
	//Users will choose what criteria to sort with by numerical value
	int choice_one;
	int choice_two;
	
	sort_criteria(choice_one, choice_two); //Function which prompts user to choose what criteria to sort by
	display_borders(choice_one); //Displays the non-numerical information of the sorting times, from displaydata.cpp

	choose_rand_alg(arr_one,arr_two,size_one,size_two,choice_one,choice_two); //Chooses and launches a random n^2 algorithm along with merge sort

	output_data(arr_one,size_one,choice_one,choice_two); //Outputs sorted data of array one
    output_data(arr_two,size_two,choice_one,choice_two); //Outputs sorted data of array two
 
	//Permanently sorts array one and two so its data can be saved
	merge_sort(arr_one,0,size_one-1,choice_one);
	merge_sort(arr_two,0,size_two-1,choice_two);

	save_and_quit(arr_one, arr_two,size_one,size_two);//Function gives user option to save and quit, function from save.cpp
	
	
	
}

/**
 * User given the option to choose what criteria to sort by
 * @param choice_one First choice of criteria, passed by reference
 * @param choice_two Second choice of criteria, passed by reference
**/
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

/**
 * Array copies one array to the other
 * @param arr_one Country array one
 * @param arr_two Country array two
 * @param size of index (size of index shared between two arrays)
**/
void copy_array(Country* arr_one, Country* arr_two, int size) {
	for (int i = 0; i < size;i++) {
		arr_one[i] = arr_two[i];
	}
}
/**
 * Launches sorting 4 sorting algorithms for sorting criteria one and two of the smallfile
 * @param arr_one Country array one holding values from small file
 * @param size_one Size of index of country array one
 * @param choice_one Criteria one to be sorted by
 * @param choice_two Criteria two to be sorted by
**/
void launch_smallfile(Country *arr_one, int size_one, int choice_one, int choice_two) {
	launch_merge(arr_one,0,size_one-1,choice_one);
	launch_insertion(arr_one, size_one,choice_one);
	launch_bubble(arr_one, size_one,choice_one);
	launch_selection(arr_one, size_one,choice_one);
	
	launch_merge(arr_one,0,size_one-1,choice_two);
	launch_insertion(arr_one, size_one,choice_two);
	launch_bubble(arr_one, size_one,choice_two);
	launch_selection(arr_one, size_one,choice_two);
	
}

/**
 * Launches sorting 4 sorting algorithms for sorting criteria one and two of the bigfile
 * @param arr_two Country array one holding values from big file
 * @param size_two Size of index of country array two
 * @param choice_one Criteria one to be sorted by
 * @param choice_two Criteria two to be sorted by
**/
void launch_bigfile(Country *arr_two,int size_two,int choice_one, int choice_two) {
	launch_merge(arr_two,0,size_two-1,choice_one);
	launch_insertion(arr_two, size_two,choice_one);
	launch_bubble(arr_two, size_two,choice_one);
	launch_selection(arr_two, size_two,choice_one);
	
	launch_merge(arr_two,0,size_two-1,choice_two);
	launch_insertion(arr_two, size_two,choice_two);
	launch_bubble(arr_two, size_two,choice_two);
	launch_selection(arr_two, size_two,choice_two);
}

/**
 * Launches bubblesort and finds average sorting time
 * also displays sorting time data
 * @param arr Country array 
 * @param size Size of index of Country array
 * @param choice Criteria to be sorted by
**/
void launch_bubble(Country* arr, int size, int choice) {
	double time = 0.0;//Value will hold the average time of sorting process
	Country *copy = new Country[size]; //Creating a backup copy for main array
	copy_array(copy,arr,size); //Backing up main array to copy

	for (int i = 0; i < 5; i++) { //For loop set to 5 to find the average of times
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		new_bubblesort(arr,size,choice); //Sorting the main array by bubble sort
		high_resolution_clock::time_point t2 = high_resolution_clock::now(); //Timed the array sorting process
		time += duration_cast<duration<double>>(t2 - t1).count(); //Times add up to find average
		copy_array(arr,copy,size); //Main array is set back equal to its original self
	}

	delete[] copy; //Once for loop completes, backup array deleted

	time = time / 5; //Time average will be found
	display_sort_times(get_criteria(choice),time,"Bubble Sort",choice,size);//Displays average time and other relevant information, from displaydata.cpp

}

/**
 * Launches selection sort and finds average sorting time
 * also displays sorting time data
 * @param arr Country array 
 * @param size Size of index of Country array
 * @param choice Criteria to be sorted by
**/
void launch_selection(Country* arr, int size, int choice) {
	double time = 0.0; //Value will hold the average time of sorting process
	Country *copy = new Country[size]; //Creating a backup copy for main array
	copy_array(copy,arr,size); //Backing up main array to copy

	for (int i = 0; i < 5; i++) { //For loop set to 5 to find the average of times
		high_resolution_clock::time_point t1 = high_resolution_clock::now(); 
		selection_sort(arr,size,choice); //Sorting the main array by selection sort
		high_resolution_clock::time_point t2 = high_resolution_clock::now(); //Timed the array sorting process
		time += duration_cast<duration<double>>(t2 - t1).count(); //Times add up to a total
		copy_array(arr,copy,size); //Main array is set back equal to its original self
	}

	delete[] copy; //Once for loop completes, backup array deleted

	time = time / 5;//Time average will be found
	display_sort_times(get_criteria(choice),time,"Selection Sort",choice,size); //Displays average time and other relevant information, from displaydata.cpp
}

/**
 * Launches insertion sort and finds average sorting time
 * also displays sorting time data
 * @param arr Country array 
 * @param size Size of index of Country array
 * @param choice Criteria to be sorted by
**/
void launch_insertion(Country* arr, int size, int choice) {
	double time = 0.0; //Value will hold the average time of sorting process
	Country *copy = new Country[size]; //Creating a backup copy for main array
	copy_array(copy,arr,size); //Backing up main array to copy

	for (int i = 0; i < 5; i++) { //For loop set to 5 to find the average of times
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		insertion_sort(arr,size,choice); //Sorting the main array by insertion sort
		high_resolution_clock::time_point t2 = high_resolution_clock::now(); //Timed the array sorting process
		time += duration_cast<duration<double>>(t2 - t1).count(); //Times add up to a total
		copy_array(arr,copy,size); //Main array is set back equal to its original self
	}

	delete[] copy; //Once for loop completes, backup array deleted

	time = time / 5; //Time average will be found
	display_sort_times(get_criteria(choice),time,"Insertion Sort",choice,size); //Displays average time and other relevant information, from displaydata.cpp
}

/**
 * Launches merge sort and finds average sorting time
 * also displays sorting time data
 * @param arr Country array 
 * @param from beginning of array range
 * @param to end of array range
 * @param choice Criteria to be sorted by
**/
void launch_merge(Country *arr, int from, int to,int choice) {
	double time = 0.0; //Value will hold the average time of sorting process
	Country *copy = new Country[to]; //Creating a backup copy for main array
	copy_array(copy,arr,to); //Backing up main array to copy

	for (int i = 0; i < 5; i++) { //For loop set to 5 to find the average of times
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		merge_sort(arr,0,to,choice);  //Sorting the main array by merge sort
		high_resolution_clock::time_point t2 = high_resolution_clock::now(); //Timed the array sorting process
		time += duration_cast<duration<double>>(t2 - t1).count(); //Times add up to a total
		copy_array(arr,copy,to); //Main array is set back equal to its original self
	}

	delete[] copy; //Once for loop completes, backup array deleted

	time = time / 5; //Time average will be found
	display_sort_times(get_criteria(choice),time,"Merge Sort",choice,to); //Displays average time and other relevant information
}

/**
 * Function that chooses a random n^2 algorithm to launch
 * Only one nlogn function (Merge Sort) no quicksort :(
 * @param arr_one Country array one
 * @param arr_two Country array two
 * @param size_one Size of array one index
 * @param size_two Size of array two index
 * @param choice_one Criteria one to be sorted by
 * @param choice_two Criteria two to be sorted by
**/
void choose_rand_alg(Country *arr_one,Country* arr_two,int size_one,int size_two,int choice_one, int choice_two) {
	int random = 0;//Random number to be generated
	srand(time(NULL)); //using internal clock to initialize random number generator
	for (int i = 0; i < 5; i++) {
		random = rand() % 3 + 1; //Generated number (from 1-3) will determine what algorithm will be merged
	}
	switch (random) { //Based off the random number generator, certain algorithms will launch
		case 1:
			launch_merge(arr_one,0,size_one-1,choice_one);
			launch_merge(arr_one,0,size_one-1,choice_two);
			launch_selection(arr_one,size_one,choice_one);
			launch_selection(arr_one,size_one,choice_two);
			
			launch_merge(arr_two,0,size_two-1,choice_one);
			launch_merge(arr_two,0,size_two-1,choice_two);
			launch_selection(arr_two,size_two,choice_one);
			launch_selection(arr_two,size_two,choice_two);
			
			break;
		case 2:
			launch_merge(arr_one,0,size_one-1,choice_one);
			launch_merge(arr_one,0,size_one-1,choice_two);
			launch_bubble(arr_one,size_one,choice_one);
			launch_bubble(arr_one,size_one,choice_two);
			
			launch_merge(arr_two,0,size_two-1,choice_one);
			launch_merge(arr_two,0,size_two-1,choice_two);
			launch_bubble(arr_two,size_two,choice_one);
			launch_bubble(arr_two,size_two,choice_two);
			
			break;
		case 3:
			launch_merge(arr_one,0,size_one-1,choice_one);
			launch_merge(arr_one,0,size_one-1,choice_two);
			launch_insertion(arr_one,size_one,choice_one);
			launch_insertion(arr_one,size_one,choice_two);

			launch_merge(arr_two,0,size_two-1,choice_one);
			launch_merge(arr_two,0,size_two-1,choice_two);
			launch_insertion(arr_two,size_two,choice_one);
			launch_insertion(arr_two,size_two,choice_two);
			
			break;
	}
	
}




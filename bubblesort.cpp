#include "bubblesort.h"

/**
 * Boolean that tests the comparison between the array index value and value before it
 * Helper function for main bubblesort algorithm
 * @param arr Country array which stores country objects
 * @param index Current position of array index
 * @param choice What criteria user wanted to sort by
**/
bool criteria_sort(Country* arr, int index, int choice) {
    switch (choice) {
        case 1: 
            return arr[index].get_name() < arr[index - 1].get_name();
        case 2:
            return arr[index].get_code() < arr[index - 1].get_code();
        case 3:
            return arr[index].get_calling() < arr[index - 1].get_calling();
        case 4:
            return arr[index].get_year() < arr[index - 1].get_year();
        case 5:
            return arr[index].get_emissions() < arr[index - 1].get_emissions();
        case 6:
            return arr[index].get_population() < arr[index - 1].get_population();
        case 7:
            return arr[index].get_area() < arr[index - 1].get_area();
        case 8:
            return arr[index].get_percent() < arr[index - 1].get_percent();
        case 9:
            return arr[index].get_density() < arr[index - 1].get_density();
        default:
            return false;
    }
}

/**
 * Optimized bubble sort function
 * Attained by collaborating with group members earlier this semester
 * Function will be quick for sorted arrays, but slow for virtually everything else
 * @param arr Country array which stores country objects
 * @param sie Array size
 * @param choice criteria to be sorted
**/
void new_bubblesort(Country* arr, int size,int choice) {
    bool swapped = true; //Boolean tests whether or not the array is in sorted order
        while (swapped) { 
        swapped = false; //Bool set to false for every pass in case later conditional is false
        for (int i = 1; i < size; i++) { 
            bool comparison = criteria_sort(arr, i, choice); //setting another comparison equal to conditional which is needed
            if (comparison) { //If the condition is met, following actions within statement occur
                swap(arr[i], arr[i - 1]); //Swaps array values
                swapped = true; //sets bool to true meaning more sorting is necessary
            }
        }
    }
}

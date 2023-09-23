#include "insertionsort.h"

/**
 * Helper function to insertion sort
 * Return true or false if the conditional is met
 * In the case of insertion sort, value of arr[index-1] has to be greater than value 
 * of next
 * @param arr Country array
 * @param next A country object which will be compared to the array at some index
 * @param index The current index
 * @param choice Numerical value which determines the criteria to be sorted by
**/
bool insertion_criteria(Country*arr, Country next ,int index, int choice) {
	switch (choice) {
        case 1: 
            return arr[index-1].get_name() > next.get_name();
        case 2:
            return arr[index-1].get_code() > next.get_code();
        case 3:
            return arr[index-1].get_calling() > next.get_calling();
        case 4:
            return arr[index-1].get_year() > next.get_year();
        case 5:
            return arr[index-1].get_emissions() > next.get_emissions();
        case 6:
            return arr[index-1].get_population() > next.get_population();
        case 7:
            return arr[index-1].get_area() > next.get_area();
        case 8:
            return arr[index-1].get_percent() > next.get_percent();
        case 9:
            return arr[index-1].get_density() > next.get_density();
        default:
            return false;
    }
}

/**
 * The insertion sort algorithm
 * @param arr Country array
 * @param size Size of the array index
 * @param choice Numerical value which determines the criteria to be sorted by
 * @https://learn.zybooks.com/zybook/OHLONECS124ChenhansaFall2023/chapter/14/section/5
**/
void insertion_sort(Country* arr, int size,int choice) {
	for (int i = 1; i < size; i++)
   {
      Country next = arr[i];
      // Move all larger elements up
      int j = i;
      
      while (j > 0 && insertion_criteria(arr, next, j, choice)) //Insertion_criteria replaces "a[j - 1] > next"
      //Insertion_criteria() is practically doing the same thing but with the sorting criteria in mind
      {
         arr[j] = arr[j - 1];
         j--;
      }
      arr[j] = next;
   }
}

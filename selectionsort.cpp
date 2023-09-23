#include "selectionsort.h"


/**
 * Helper function to selection sort
 * Function replaces "if (a[i] < a[min_pos])"
 * Necessary if wanting to sort through multiple criterias
 * @param arr Country array
 * @param index Current index of array
 * @param min_pos Postion of smallest element in array
 * @param choice Numerical value which represents criteria to be sorted by
**/
bool selection_criteria(Country* arr, int index, int min_pos, int choice){
	switch (choice) {
        case 1: 
            return arr[index].get_name() < arr[min_pos].get_name();
        case 2:
            return arr[index].get_code() < arr[min_pos].get_code();
        case 3:
            return arr[index].get_calling() < arr[min_pos].get_calling();
        case 4:
        	return arr[index].get_year() < arr[min_pos].get_year();
        case 5:
            return arr[index].get_emissions() < arr[min_pos].get_emissions();
        case 6:
            return arr[index].get_population() < arr[min_pos].get_population();
        case 7:
            return arr[index].get_area() < arr[min_pos].get_area();
        case 8:
            return arr[index].get_percent() < arr[min_pos].get_percent();
        case 9:
            return arr[index].get_density() < arr[min_pos].get_density();
        default:
            return false;
    }
}

/**
 * Gets position of smallest element in array
 * @param arr Country array
 * @param from beginning of array range
 * @param to end of array range
 * @param choice Numerical value which represents criteria to be sorted by
**/
int min_position(Country* arr, int from, int to,int choice) {
   int min_pos = from;
   for (int i = from + 1; i <= to; i++)
   {
   	  bool comparison = selection_criteria(arr,i,min_pos,choice);
      if (comparison) { min_pos = i; }
   }
   return min_pos;
}

/**
 * Actual selection sort algorithm
 * @param arr Country array
 * @param size Size of array index
 * @param choice Numerical value which represents criteria to be sorted by
**/
void selection_sort(Country* arr, int size,int choice) {
   int next; // The next position to be set to the minimum
   for (next = 0; next < size - 1; next++)
   {
      // Find the position of the minimum starting at next
      int min_pos = min_position(arr, next, size - 1,choice);
      // Swap the next element and the minimum
      swap(arr[next], arr[min_pos]); //Swap is from swap.cpp
   }
}
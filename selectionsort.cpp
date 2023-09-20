#include "selectionsort.h"


bool selection_criteria(Country* arr, int index, int min_pos, int choice){
	std::string arr_one;
	std::string arr_two;
	switch (choice) {
        case 1: 
            return arr[index].get_name() < arr[min_pos].get_name();
        case 2:
            return arr[index].get_code() < arr[min_pos].get_code();
        case 3:
            return arr[index].get_calling() < arr[min_pos].get_calling();
        case 4:
        	arr_one = arr[index].get_year();
        	arr_two = arr[min_pos].get_year();
        	if (arr_one < arr_two && arr_one.length() < arr_two.length()) {
        		return true;
        	}
        case 5:
            return arr[index].get_emissions() < arr[min_pos].get_emissions();
        case 6:
            return arr[index].get_population() < arr[min_pos].get_population();
        case 7:
            return arr[index].get_area() < arr[min_pos].get_area();
        case 8:
            return arr[index].get_percent() < arr[min_pos].get_percent();
        case 9:
            arr_one = arr[index].get_density();
        	arr_two = arr[min_pos].get_density();
        	if (arr_one.length() < arr_two.length()) {
        		if (stoi(arr_one) < stoi(arr_two)) {
        			if (arr_one < arr_two) {
        				return true;
        			}
        		}
        	}

        default:
            return false;
    }
}

int min_position(Country* arr, int from, int to,int choice) {
   int min_pos = from;
   for (int i = from + 1; i <= to; i++)
   {
   	  bool comparison = selection_criteria(arr,i,min_pos,choice);
      if (comparison) { min_pos = i; }
   }
   return min_pos;
}

void selection_sort(Country* arr, int size,int choice) {
   int next; // The next position to be set to the minimum
   for (next = 0; next < size - 1; next++)
   {
      // Find the position of the minimum starting at next
      int min_pos = min_position(arr, next, size - 1,choice);
      // Swap the next element and the minimum
      swap(arr[next], arr[min_pos]);
   }
}
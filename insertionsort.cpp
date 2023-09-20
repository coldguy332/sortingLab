#include "insertionsort.h"

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

void insertion_sort(Country* arr, int size,int choice) {
	for (int i = 1; i < size; i++)
   {
      Country next = arr[i];
      // Move all larger elements up
      int j = i;
      
      while (j > 0 && insertion_criteria(arr, next, j, choice))
      {
         arr[j] = arr[j - 1];
         j--;
      }
      arr[j] = next;
   }
}

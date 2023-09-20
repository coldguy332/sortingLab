#include "bubblesort.h"

void swap(Country& a, Country& b) {
    Country temp = a;
    a = b;
    b = temp;
}

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


/*
void bubble_sort(Country* arr, int index, int choice) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < index; i++) { 
            if (arr[i].get_emissions() < arr[i-1].get_emissions()) {
                swap(arr[i], arr[i-1]);
                swapped = true;
            }

            /*)
            bool criteria_comparison = criteria_sort(arr, i, choice);
            if (criteria_comparison == true) {
                swap(arr[i], arr[i - 1]); 
                swapped = true;
            }
          

        }
    }
}  
*/


 void new_bubblesort(Country* arr, int index,int choice) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < index; i++) { 
            bool comparison = criteria_sort(arr, i, choice);
            if (comparison) {
                swap(arr[i], arr[i - 1]); 
                swapped = true;
            }
        }
    }
}

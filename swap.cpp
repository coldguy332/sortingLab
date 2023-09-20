#include "swap.h"

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
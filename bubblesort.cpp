#include "bubblesort.h"

void swap(Country& a, Country& b) {
    Country temp = a;
    a = b;
    b = temp;
}

void new_bubblesort(Country* arr, int index) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < index; i++) { 
            if (arr[i].get_area() < arr[i - 1].get_area()) {
                swap(arr[i], arr[i - 1]); 
                swapped = true;
            }
        }
    }
}

 


void sort_by_criteria(*Country arr, int counter, int choice, bool& swapped) {
    switch(choice) {
        case 1:
            if (arr[counter].get_name() < arr[counter-1].get_name()) {
                swap(arr[counter], arr[counter - 1]); 
                swapped = true;
                break;
            }
        case 2:
            if (arr[counter].get_name() < arr[counter-1].get_name()) {
                swap(arr[counter], arr[counter - 1]); 
                swapped = true;
                break;
            }
        case 3:
            if (arr[counter].get_name() < arr[counter-1].get_name()) {
                swap(arr[counter], arr[counter - 1]); 
                swapped = true;
                break;
            }
        case 4:
            if (arr[counter].get_name() < arr[counter-1].get_name()) {
                swap(arr[counter], arr[counter - 1]); 
                swapped = true;
                break;
            }
        case 5:
            if (arr[counter].get_name() < arr[counter-1].get_name()) {
                swap(arr[counter], arr[counter - 1]); 
                swapped = true;
                break;
            }
        case 6:
            if (arr[counter].get_name() < arr[counter-1].get_name()) {
                swap(arr[counter], arr[counter - 1]); 
                swapped = true;
                break;
            }
        case 7:
            if (arr[counter].get_name() < arr[counter-1].get_name()) {
                swap(arr[counter], arr[counter - 1]); 
                swapped = true;
                break;
            }
        case 8:
            
        case 9:
    }
}


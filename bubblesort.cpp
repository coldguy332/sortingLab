#include "bubblesort.h"



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

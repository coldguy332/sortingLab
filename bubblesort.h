#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "country.h"

void swap(Country& a, Country& b);
bool criteria_sort(Country* arr, int index, int choice);
void new_bubblesort(Country* arr, int index,int choice);


#endif
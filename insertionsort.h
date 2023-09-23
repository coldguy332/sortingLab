//
// Created by Amal Afsal for Sorting lab on 9/18/23.
//

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>
#include "country.h"

bool insertion_criteria(Country*arr, Country next ,int index, int choice);
void insertion_sort(Country* arr, int size,int choice);


#endif
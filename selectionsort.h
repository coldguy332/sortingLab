//
// Created by Amal Afsal for Sorting lab on 9/18/23.
//

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <string.h>
#include "country.h"
#include "swap.h"


bool selection_criteria(Country* arr, int index, int min_pos, int choice);
int min_position(Country* arr, int from, int to,int choice);
void selection_sort(Country* arr, int size,int choice);


#endif

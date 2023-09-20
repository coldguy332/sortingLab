#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include "country.h"

bool merge_comparison(Country* arr, int i1, int i2, int choice);
void merge(Country* arr, int from, int mid, int to,int choice);
void merge_sort(Country *arr, int from, int to,int choice);

#endif
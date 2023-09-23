#ifndef DISPLAYDATA_H
#define DISPLAYDATA_H

#include <iostream>
#include <iomanip>

#include "sorter.h" //For copying array function
#include "country.h"
#include "mergesort.h"

std::string get_criteria(int choice);
std::string already_sorted_check(int choice);


void display_sort_times(std::string criteria, double time, std::string sort_name,int choice,int index);
void display_borders(int choice);
void output_data(Country* arr,int index, int choice_one,int choice_two);
void display_sorted_left(Country* arr,int index, int choice);
void display_sorted_right(Country*arr,int index,int choice);
std::string big_or_small(int index);

#endif
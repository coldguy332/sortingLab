#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <ratio>
#include <chrono>

#include "country.h"
#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "mergesort.h"

void all_algos(Country *arr_one, Country *arr_two,int index_one, int index_two);

void rand_algos(Country *arr_one, Country *arr_two,int index_one, int index_two);

void sort_criteria(int& choice_one, int& choice_two);

void launch_smallfile(Country *arr_one, int index_one, int choice_one, int choice_two);
void launch_bigfile(Country *arr_two,int index_two,int choice_one, int choice_two);

void launch_bubble(Country* arr, int index, int choice);
void launch_selection(Country* arr, int index, int choice);
void launch_insertion(Country* arr, int index, int choice);
void launch_merge(Country *arr, int from, int to,int choice);

void choose_rand_alg(Country *arr, int index, int choice_one, int choice_two);
std::string get_criteria(int choice);
std::string already_sorted_check(int choice);

void display_borders(int choice);

#endif
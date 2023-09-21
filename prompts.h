#ifndef PROMPTS_H
#define PROMPTS_H

#include <iostream>

#include "datainput.h"
#include "country.h"
#include "sorter.h"
#include "save.h"

void welcome_prompt();
void choosing_algorithm(Country *arr_one, Country *arr_two, int index_one, int index_two);
void save_and_quit(Country* arr_one, Country* arr_two, int index_one, int index_two);

#endif 
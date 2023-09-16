#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "country.h"

void create_array();
void array_filler(std::ifstream& in_file, Country *arr, int index);
int line_counter(std::ifstream& in_file);

#endif
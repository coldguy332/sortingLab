#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "country.h"
#include "prompts.h"
#include "bubblesort.h"

void create_array();
void array_filler(std::ifstream& in_file, Country *arr, int index);
void unknown_checker(std::string& temp_name, std::string& temp_code, std::string& temp_calling, std::string& temp_year ,
			std::string& temp_emissions, std::string& temp_population, std::string& temp_area, std::string& temp_percent, std::string& temp_density);
int line_counter(std::ifstream& in_file);
void quoted_field_code(std::stringstream& ss, std::string& temp_string);
void quoted_field_density(std::stringstream& ss, std::string& temp_string);
void density_check(std::string& density);
void comma_remover(std::string& temp_string);
void dash_remover(std::string& temp_string);

#endif
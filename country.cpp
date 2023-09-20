#include "country.h"

Country::Country() {
	this->country_name = "";
	this->code = "";
	this->calling_code = "";
	this->year = 0;
	this->emissions = 0;
	this->population = 0;
	this->area = 0;
	this->percent = 0.0;
	this->density = "";
}

Country::Country(std::string country_name, std::string code, std::string calling_code, int year ,
	long int emissions, long int population, int area, double percent, std::string density) {
	this->country_name = country_name;
	this->code = code;
	this->calling_code = calling_code;
	this->year = year;
	this->emissions = emissions;
	this->population = population;
	this->area = area;
	this->percent = percent;
	this->density = density;
}

std::string Country::get_name() const {
	return this->country_name;
}
std::string Country::get_code() const {
	return this->code;
}
std::string Country::get_calling() const {
	return this->calling_code;
}
int Country::get_year() const {
	return this->year;
}
long int Country::get_emissions() const {
	return this->emissions;
}
long int Country::get_population() const {
	return this->population;
}
int Country::get_area() const {
	return this->area;
}
double Country::get_percent() const {
	return this->percent;
}
std::string Country::get_density() const {
	return this->density;
}



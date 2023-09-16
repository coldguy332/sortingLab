#include "country.h"

Country::Country() {
	this->country_name = "";
	this->code = "";
	this->calling_code = "";
	this->year = "";
	this->emissions = "";
	this->population = "";
	this->area = "";
	this->percent = "";
	this->density = "";
}

Country::Country(std::string country_name, std::string code, std::string calling_code, std::string year ,
	std::string emissions, std::string population, std::string area, std::string percent, std::string density) {
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
std::string Country::get_year() const {
	return this->year;
}
std::string Country::get_emissions() const {
	return this->emissions;
}
std::string Country::get_population() const {
	return this->population;
}
std::string Country::get_area() const {
	return this->area;
}
std::string Country::get_percent() const {
	return this->percent;
}
std::string Country::get_density() const {
	return this->density;
}

#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>

class Country {
	public:
		Country();
		Country(std::string country_name, std::string code, std::string calling_code, int year ,int emissions, int population, int area, int percent, int density);
		std::string get_name() const;
		std::string get_code() const;
		std::string get_calling() const;
		int get_year() const;
		int get_emissions() const;
		int get_population() const;
		int get_area() const;
		int get_percent() const;
		int get_density() const;

	private:
		std::string country_name;
		std::string code;
		std::string calling_code; //For now this remains a string
		int year;
		int emissions;
		int population;
		int area;
		int percent;
		int density;

};

#endif 


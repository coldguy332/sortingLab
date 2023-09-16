#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>

class Country {
	public:
		Country();
		Country(std::string country_name, std::string code, std::string calling_code, std::string year ,
			std::string emissions, std::string population, std::string area, std::string percent, std::string density);
		std::string get_name() const;
		std::string get_code() const;
		std::string get_calling() const;
		std::string get_year() const;
		std::string get_emissions() const;
		std::string get_population() const;
		std::string get_area() const;
		std::string get_percent() const;
		std::string get_density() const;

	private:
		std::string country_name;
		std::string code;
		std::string calling_code; //For now this remains a string
		std::string year;
		std::string emissions;
		std::string population;
		std::string area;
		std::string percent;
		std::string density;

};

#endif 


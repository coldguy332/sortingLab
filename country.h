#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>

class Country {
	public:
		Country();
		Country(std::string country_name, std::string code, std::string calling_code, int year ,
			long int emissions, long int population, long int area, std::string percent, std::string density);

		std::string get_name() const;
		std::string get_code() const;
		std::string get_calling() const;
		int get_year() const;
		long int get_emissions() const;
		long int get_population() const;
		long int get_area() const;
		std::string get_percent() const;
		std::string get_density() const;

		std::string get_data(char choice) const;
		long int get_data(int choice) const;



	private:
		std::string country_name; 'A'
		std::string code; 'B'
		std::string calling_code; 'C'
		int year; // 1
		long int emissions; // 2
		long int population; //3
		long int area; //4
		std::string percent; 'D'
		std::string density; 'E'

};

/*
	output what criteria user wants to choose between 1 - 9


*/


#endif 


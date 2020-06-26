#ifndef W5N_DATETIME_H
#define W5N_DATETIME_H
#include <sstream>
#include <iostream>
#include <string>

struct Date
{
	int year;
	int month;
	int day;
	void set_from_string(std::string date); 
	std::string to_string();
};

struct Time
{
	int hour;
	int minute;
	int second;
	void set_from_string(const std::string& time);
    std::string to_string();

};
#endif
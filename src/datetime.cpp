#include "datetime.h"

#include <sstream>

Date::Date() : year(0), month(0), day(0) {
}
void Date::set_from_string(const std::string& date){
	 Date d;
    std::stringstream stream(date);
    char discard;

    stream >> d.day >> discard >> d.month >> discard >> d.year;
}
std::string Date::to_string() {
	std::stringstream stream;
	stream << day << "/" << month << year;	
  return stream.str();
}

Time::Time() : hour(0), minute(0), second(0) {

}

void Time::set_from_string(const std::string& time){
  Time t;

    std::stringstream stream(time);
    char discard;

    stream >> t.hour >> discard >> t.minute >> discard >> t.second;
}

std::string Time::to_string() {
  std::stringstream stream;
  stream << hour << "/" << minute << "/" << second;  
  return stream.str();
}
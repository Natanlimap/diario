#include "datetime.h"

void Date::set_from_string(std::string date){
	 Date d;
    std::stringstream stream(date);
    char discard;
    stream >> d.day;
    stream >> discard;
    stream >> d.month;
    stream >> discard;
    stream >> d.year; 
    day = d.day;
    month = d.month;
    year = d.year;
}

std::string Date::to_string() {
	std::stringstream stream;
  if(day < 9){
    stream << "0";
  }
  stream << day << "/";
  if(month < 9){
      stream << "0";

  }
	stream << month << "/";
  stream  << year;	
  return stream.str();
}



void Time::set_from_string(const std::string& time){
    Time d;
    std::stringstream stream(time);
    char discard;
    stream >> d.hour;
    stream >> discard;
    stream >> d.minute;
    stream >> discard;
    stream >> d.second; 
    hour = d.hour;
    minute = d.minute;
    second = d.second;
}

std::string Time::to_string() {
  std::stringstream stream;
   if(hour <= 9){
    stream << "0"; 
  }
  stream << hour << ":";
  if(minute <= 9){
      stream << "0";
  }
  stream << minute << ":";
  if(second <= 9){
      stream << "0";
  }
  stream << second;

  return stream.str();
}
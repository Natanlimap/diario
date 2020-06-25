#ifndef W5N_MESSAGE_H
#define W5N_MESSAGE_H

#include "datetime.h"

#include <string>


struct Message{
	Date date;
	Time time;
	std::string content;
};

#endif
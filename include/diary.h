#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "../include/message.h"
#include "../include/datetime.h"
#include <string>
#include <iostream>

struct Diary{

	std::string filename;
	size_t size;
	size_t max;
	Message *messages;

	Diary(const std::string &filename);
	bool dayExists(const Message message);
    void add(const std::string& message);
    void write();
	void list();

};


#endif
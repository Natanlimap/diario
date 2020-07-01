#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include <sstream>
#include "../include/message.h"
#include "../include/datetime.h"
#include <string>
#include <iostream>
#include <fstream>
#include <datetime.h>
#include <vector>

struct Diary{

	std::string filename;
	size_t size;
	size_t max;
	std::vector<Message> messages;

	Diary(const std::string &filename);
	~Diary();

	bool dayExists(const Message message);
    void add(const std::string& message, Date mdate, Time mtime);
    void write();
	void list();
	std::vector<Message> search(std::string what);
	void loadMessage();


};


#endif
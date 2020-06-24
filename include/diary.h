#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "../include/Message.h"
#include "../include/datetime.h"
#include <string>

struct Diary{

	std::string filename;
	size_t size;
	size_t max;
	Message messages

	Diary(const std::string &filename);
	bool dayExists(const Message message);
	void add(const Message message);
	void write();
	void list();

}


#endif
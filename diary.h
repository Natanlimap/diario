#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <string>

struct Diary{

	std::string filename;

	std::list<Message> messages;

	bool dayExists(const Message message);

	void add(const Message message);
	
	void write();
	
	bool diaryExist(); 
}


#endif
#include "diary.h"

Diary::Diary(const std::string& filename): filename(filename), max(10), size(0), messages(nullptr){
        messages = new Message[capacity];
}

void Diary::add(const std::string& message) {
    if(size < max){
    	Message new_message (message, date, time);
    	messages[size] = new_message;
    	size++;
    }
}

	
void Diary::write(){

}
	
bool Diary::list(){
	for(int i =0 ; i < size; i++){
		std::cout << messages[i].content << std::endl;
	}
}

#include "diary.h"

Diary::Diary(const std::string& filename): filename(filename), max(10), size(0), messages(nullptr){
        messages = new Message[max];
}



void Diary::add(const std::string& message)
{
    if (size >= max) {
        return;
    }

    Message m;
    m.content = message;

    messages[size] = m;
    size++;
}



void Diary::write(){

}
	
void Diary::list(){
	for(int i =0 ; i < size; i++){
		std::cout << messages[i].content << std::endl;
	}
}

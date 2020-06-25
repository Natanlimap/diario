#include <iostream>
#include <string.h>

#include "../include/app.h"
#include "../include/message.h"

App::App(const std::string &filename): diary(filename) {

}

void App::add()
{
	
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
}


void App::list()
{
    for (size_t i = 0; i < diary.size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}


int App::showUsage(){
		std::cout << "Uso:" << std::endl << "./diary add" << std::endl << "./diary add <message>" << std::endl << "./diary list" << std::endl; //Mostra para o usuario a entrada correta para o programa.
		return 1;
}


int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return showUsage();
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list();
    } else if (action == "search") {
    } else {
        return showUsage();
    }

    return 0;
}



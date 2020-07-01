#include <iostream>
#include <string.h>
#include <util.h>
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
    std::cout << message << std::endl;
    Date date;
    date.set_from_string(get_current_date());
    Time time;
    time.set_from_string(get_current_time());
    diary.add(message, date, time);
    diary.write();
}


void App::list()
{
    diary.list();
}

void App::search(std::string what)
{
    std::vector<Message> printer = diary.search(what);

   for (auto const& i: printer) {
        std::cout << i.content << std::endl;
    }
}
int App::showUsage(){
		std::cout << "Uso:" << std::endl << "./diary add" << std::endl << "./diary add <message>" << std::endl << "./diary list" << std::endl << "./diary search"<<std::endl<< "./diary search <message>" << std::endl; //Mostra para o usuario a entrada correta para o programa.
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
          if (argc == 2) {
            std::string what;
            std::cin >> what;
            search(what);
        } else {
            search(argv[2]);
        }
    } else {
        return showUsage();
    }

    return 0;
}



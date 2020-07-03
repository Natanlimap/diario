#ifndef W5N_APP_H
#define W5N_APP_H

#include "diary.h"
#include <vector>
#include <string>

struct App
{
    Diary diary;

    App(const std::string& filename);
    int run(int argc, char* argv[]);
	int showUsage();
    void add();
    void add(const std::string message);
    void search(std::string what);
    int filterAction(int argc, char *argv[]);
    void interactive();


};
#endif
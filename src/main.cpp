#include "app.h"

int main(int argc, char* argv[])
{
    App aplicativo("diary.md");
    aplicativo.run(argc, argv);
    aplicativo.diary.list();
    
}
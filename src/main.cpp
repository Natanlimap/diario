#include "app.h"

int main(int argc, char* argv[])
{
    App aplicativo("diary.md");
    aplicativo.run(argc, argv);

    for (int i = 0; i < 20; ++i)
    {
    	aplicativo.add("a");
    }
}
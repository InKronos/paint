#include "stdafx.h"
#include "Application.h"


int main()
{
    std::string filename;
    std::cout << "Type a name of a file, that your work with be save in: ";
    std::cin >> filename;
    Application app(800, 400, filename);
    app.run();
    return 0;
}
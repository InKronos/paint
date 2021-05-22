#include "stdafx.h"
#include "Application.h"
#include <regex> 

int main()
{
    std::regex corectFileName("([1-9A-Za-z])*");
    std::string filename = "";
    do {
        std::cout << "Type a alphanumeric name of a file, that your work with be save in: ";
        std::cin >> filename;
    } while (!std::regex_match(filename, corectFileName));
  
    Application app(800, 400, filename);
    app.run();
    return 0;
}
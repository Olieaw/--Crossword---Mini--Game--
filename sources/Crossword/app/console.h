#ifndef CONSOLE_H
#define CONSOLE_H

#include "vocalbulary.h"
#include "field.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

class Console
{
public:
    Console();

    void Menu();
    void PrintWords(std::vector<std::string> str);
    void PrintField(std::vector<std::vector<std::string>> field);
};

#endif // CONSOLE_H

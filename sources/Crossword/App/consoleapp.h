#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H

#include <iostream>
#include <string>
#include <vector>
//todo зачем #include <fstream>? у вас же нет работы с файлами
#include <fstream>
#include <cstring>

//todo плохой тон использовать using namespace std
using namespace std;

class ConsoleApp
{
public:

    void Menu();
};

#endif // CONSOLEAPP_H


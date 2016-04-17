#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

class Logic
{
private:
    struct WordStruct{

    char word[255];
    int lenght = 0;
    bool orientation = false;
    int wordCoord = 0;
    };

    int numberWord = 0;
    WordStruct word;
    vector<WordStruct> Vocabulary;
public:
    void Read();

    void Print();

    void If();
};

#endif // LOGIC_H

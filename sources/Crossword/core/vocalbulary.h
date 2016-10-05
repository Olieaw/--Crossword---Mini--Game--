#ifndef VOCALBULARY_H
#define VOCALBULARY_H

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

class Vocalbulary
{
protected:
    std::vector<std::string>words;
public:
    Vocalbulary();
    ~Vocalbulary();
    void AddWord(std::string word);
    void DelWord(std::string word);
    std::vector<std::string> Output();
};

#endif // VOCALBULARY_H

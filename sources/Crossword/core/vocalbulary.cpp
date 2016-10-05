#include "vocalbulary.h"


Vocalbulary::Vocalbulary()
{
}

Vocalbulary::~Vocalbulary()
{
    words.clear();
}

void Vocalbulary::AddWord(std::string word)
{
    words.push_back(word);
}

void Vocalbulary::DelWord(std::string word)
{
    for(std::vector<std::string>::iterator it = words.begin(); it<words.end(); ++it)
    {
        if(*it==word)
        {
            words.erase(it);
        }
    }
}

std::vector<std::string> Vocalbulary::Output()
{
    return words;
}

#ifndef VOCABULARY_H
#define VOCABULARY_H

#include "field.h"

#include <iostream>
#include <string>
#include <cstring>

class Vocabulary
{
    std::string word;
    Vocabulary *next;
    Vocabulary(std::string word_, Vocabulary *next_ = nullptr):word(word_), next(next_){}

    int size;
    Vocabulary *first;
    Vocabulary *last;
public:
    Vocabulary()
    {
       size = 0;
       first = last = NULL;
    }

    ~Vocabulary();

    void AddWord(std::string word);
    bool Remove(std::string word);
    void Output();
    void GenerationField();
};

#endif // VOCABULARY_H

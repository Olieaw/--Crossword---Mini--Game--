#ifndef WORKWITHVOCABULARY_H
#define WORKWITHVOCABULARY_H

#include <iostream>
#include <string>

using namespace std;

class WorkWithVocabulary
{
    struct Vocabulary
    {
        //char word[20];
        int numer;
        Vocabulary *Next;
    };
    Vocabulary *Head;
public:
    WorkWithVocabulary(){Head = 0;}
    ~WorkWithVocabulary();
    void Add(int numer);
    void Show();
};

#endif // WORKWITHVOCABULARY_H

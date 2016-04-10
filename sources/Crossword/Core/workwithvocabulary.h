#ifndef WORKWITHVOCABULARY_H
#define WORKWITHVOCABULARY_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class WorkWithVocabulary
{
    struct Vocabulary
    {
        //char word[20];
        int numer;
        Vocabulary *next;

        Vocabulary(int num, Vocabulary *n = NULL)
        {
            numer = num;
            next = n;
        }
    };
    int size;
    Vocabulary *first;
    Vocabulary *last;
public:
    WorkWithVocabulary()
    {
       size = 0;
       first = last = NULL;
    }

    ~WorkWithVocabulary();

    WorkWithVocabulary(const WorkWithVocabulary & src);

    void AddLast(const WorkWithVocabulary &src);

    void AddLast(int numer);

    int RemoveFirst();

    bool Remove(int value);

    string GetAllItemInfo();
};

#endif // WORKWITHVOCABULARY_H

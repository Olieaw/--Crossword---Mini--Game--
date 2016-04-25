#ifndef WORKWITHVOCABULARY_H
#define WORKWITHVOCABULARY_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class WorkWithVocabulary
{
    struct Vocabulary
    {
        char word[20];
        Vocabulary *next;

        Vocabulary(char w[20], Vocabulary *n = NULL)
        {
            for(int i = 0;i < 20; i++)
                word[i] = w[i];
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

    void AddLast(char *word);
    bool Remove(char *value);

    void Generation(int size);
    void GetAllItemInfo();
};

#endif // WORKWITHVOCABULARY_H

#ifndef WORKWITHVOCABULARY_H
#define WORKWITHVOCABULARY_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//todo лучше не делать самдоельые списки, а использовать стандартную бибилиотеку
class WorkWithVocabulary
{
    //todo вынести определение структуры за класс
    struct Vocabulary
    {
        //todo никаких сишных массивов
        char word[20];
        Vocabulary *next;
        //todo сhar w[20] это еще что? char*
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

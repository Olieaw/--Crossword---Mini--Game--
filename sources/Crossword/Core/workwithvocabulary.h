#ifndef WORKWITHVOCABULARY_H
#define WORKWITHVOCABULARY_H

#include <iostream>
#include <string>
#include <cstring>
//todo не использовать using namespace std - плохой тон
using namespace std;

//todo лучше не делать самдоельые списки, а использовать стандартную бибилиотеку
//todo переименовать класс, возможно более короткое название типа Vocabulary было бы лучше
//и относитесь к классу как к конкретной сущносьти
class WorkWithVocabulary
{
    //todo сделать поля структуры полями класса
    struct Vocabulary
    {
        //todo никаких сишных массивов
        //todo и магических чисел
        char word[20];
        Vocabulary *next;
        //todo использовать nullptr
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

    //todo использовать строки стандартной библиотеке вместо сишных строк
    void AddLast(char *word);
    bool Remove(char *value);
    //todo лучше использовать глаголы для названий методов
    void Generation(int size);
    void GetAllItemInfo();
};

#endif // WORKWITHVOCABULARY_H

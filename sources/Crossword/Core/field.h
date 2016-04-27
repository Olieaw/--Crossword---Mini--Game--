#ifndef FIELD_H
#define FIELD_H


#include <iostream>
#include <string>
#include <cstring>

//todo не использовать using namespace
using namespace std;

//todo лучше не делать самдоельые списки, а использовать стандартную бибилиотеку
class Field
{
    //todo не использовтаь сишные массивы
    //todo что за магические числа?
    char field[20][20];

    //todo лучше сделать классом
    struct Information
    {
        int x,y;
        int length;
        //todo не использовтаь сишные массивы
        //todo использовать строки string, а не массивы символов
        char word[20];
        bool orientation; //false - горизонтальное, true - вертикальное
        //todo вынести определение структуры за класс
        struct occupiedLetter
        {
            int x, y;
        };

        Information *next;

        //todo использовать списки инициализации
        //todo использовать nullptr а не NULL
        Information(int x_, int y_, int length_, char w[20], bool orient = false, Information *n = NULL)
        {
            x = x_;
            y = y_;
            length = length_;
            for(int i = 0;i < 20; i++)
                word[i] = w[i];
            orientation = orient;
            next = n;
        }

    };

    Information *first;
    Information *last;

    //todo вынести определение структуры за класс
    struct OccupiedLetter
    {
        int x, y;
        OccupiedLetter *next;
        //todo использовать списки инициализации
        OccupiedLetter(int x_, int y_)
        {
            x = x_;
            y = y_;
        }
    };

    OccupiedLetter *first_OcLet;
    OccupiedLetter *last_OcLet;

public:

    //todo может, лучше сделать констурктор и передовать туда всю информацию
    void AddInformation(int x, int y, int length, bool orientation, char *word);
    void GetAllItemInfo();

    void AddOccupiedLetter(int x, int y);
    void InfoOccupiedLetter();
    //todo лучше исопльзовать глалголы для названия методов
    void NewField(int size); //createNewField например
    void FirstWordVerification(int size, char *word);
    void PrintFirstWord(int size, char *word);
    void PrintNextWords(char *word);
    void PrintField(int size);
};

#endif // FIELD_H

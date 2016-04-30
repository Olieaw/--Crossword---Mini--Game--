#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <string>
#include <cstring>

//todo не использовать using namespace
using namespace std;

//todo лучше не делать самдоельные списки, а использовать стандартную бибилиотеку
class Field
{
    //todo не использовтаь сишные массивы
    //todo что за магические числа?
    char field[20][20];

    //todo лучше сделать классом
    //todo информация о чем? переименовать
    struct Information
    {
        //todo пары координат лучше хранить в отдельным классе или структуре и с ними работать
        int x,y;
        int length;
        //todo не использовтаь сишные массивы
        //todo использовать строки string, а не массивы символов
        char word[20];
        //todo лучше использовать enum со зачением HORIZONTAL и VERTICAL, что нибудь такого плана
        bool orientation; //false - горизонтальное, true - вертикальное
        //todo пары координат лучше хранить в отдельным классе и структуру можно будет заменить экземпляром того класса
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
            //todo обязательно длина слова 20 символов? Зачем все 20 копировать? И опять магические числа.
            for(int i = 0; i < 20; i++)
                word[i] = w[i];
            orientation = orient;
            next = n;
        }

    };

    Information *first;
    Information *last;

    //todo вынести определение структуры за класс и почему у нее такое же название что и occupiedLetter и что опятьза самодельные списки?
    //std::list<OccupiedLetter> и иттерироваться по нему
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


    //todo почему бы не предавать информацию объектом
    //AddInformation(Information &info);
    //todo использовать строки string
    void AddInformation(int x, int y, int length, bool orientation, char *word);
    void GetAllItemInfo();

    void AddOccupiedLetter(int x, int y);
    void InfoOccupiedLetter();
    //todo может, лучше сделать констурктор
    //todo лучше исопльзовать глалголы для названия методов
    void NewField(int size); //createNewField например
    //todo использовать строки string
    void FirstWordVerification(int size, char *word);
    //todo использовать строки string
    void PrintFirstWord(int size, char *word);
    //todo использовать строки string
    void PrintNextWords(char *word);
    void PrintField(int size);

    //todo где деструктор?
};

#endif // FIELD_H

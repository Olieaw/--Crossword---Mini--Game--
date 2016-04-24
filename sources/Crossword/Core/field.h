#ifndef FIELD_H
#define FIELD_H


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Field
{
    char field[20][20];

    struct Information
    {
        int x,y;
        int length;
        char word[20];
        bool orientation; //false - горизонтальное, true - вертикальное

        struct occupiedLetter
        {
            int x, y;
        };

        Information *next;

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

    int size;
    Information *first;
    Information *last;
public:

    void AddInformation(int x, int y, int length, bool orientation, char *word);
    void GetAllItemInfo();

    void NewField(int size);
    int If(char *word, char *word2);
    void PrintWord(int size, char *word);
    void Print(int size);
};

#endif // FIELD_H

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

    Information *first;
    Information *last;

    struct OccupiedLetter
    {
        int x, y;
        OccupiedLetter *next;

        OccupiedLetter(int x_, int y_)
        {
            x = x_;
            y = y_;
        }
    };

    OccupiedLetter *first_OcLet;
    OccupiedLetter *last_OcLet;

public:

    void AddInformation(int x, int y, int length, bool orientation, char *word);
    void GetAllItemInfo();

    void AddOccupiedLetter(int x, int y);
    void InfoOccupiedLetter();

    void NewField(int size);
    void FirstWordVerification(int size, char *word);
    void PrintFirstWord(int size, char *word);
    void PrintNextWords(char *word);
    void PrintField(int size);
};

#endif // FIELD_H

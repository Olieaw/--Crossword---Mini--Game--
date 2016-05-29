#ifndef FIELD_H
#define FIELD_H

#include "vocabulary.h"

#include <iostream>
#include <string>
#include <string>
#include <vector>

class Field
{
protected:
    const int sizeField = 20;
    std::vector<std::vector<std::string>> field;
    std::vector<std::vector<std::string>> playingField;

    struct Information
    {
        int x,y;
        int length;
        std::string word;
        int numberWord;
        bool orientation;

        Information *next;

        Information(int x_, int y_, int length_, std::string word_, int numerWord_, bool orientation_ = false, Information *next_ = nullptr):
        x(x_), y(y_), length(length_),word(word_), numberWord(numerWord_), orientation(orientation_), next(next_){}

    };

    int sizeInfo;
    Information *first;
    Information *last;

    struct OccupiedLetter
    {
        int x, y;
        OccupiedLetter *next;
        OccupiedLetter(int x_, int y_, OccupiedLetter *next_ = nullptr): x(x_), y(y_), next(next_){}
    };

    OccupiedLetter *first_OcLet;
    OccupiedLetter *last_OcLet;

public:
    Field();
    ~Field();

    void AddInformation(int x, int y, int length, bool orientation, std::string word);
    void PrintInformation();
    void GetAllItemInfo();

    void AddOccupiedLetter(int x, int y);
    void InfoOccupiedLetter();

    void FirstWordVerification(std::string word);
    void PrintNextWords(std::string word);
    bool InspectionOccupiedLetter(int x, int y);
    bool WrongIntersection(int x, int y, std::string word, bool orientation);
    void PrintField();
    void PrintFieldM();

    void AddWordsIntersection();
    void AddCellsPlayingField();
    void PrintPlayingField();
    void PrintPlayingFieldM();
    bool EnterTheWord(int number, std::string word);

    int MaxXInfoField();
    int MaxYInfoField();
    int MinXInfoField();
    int MinYInfoField();
};

#endif // FIELD_H

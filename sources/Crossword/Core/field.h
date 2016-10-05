#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <vector>
#include <iostream>

#include "vocalbulary.h"


class Field: public Vocalbulary
{
protected:
    const int sizeField = 20;

    struct InformationAboutWord
    {
        int x,y;
        int length;
        std::string word;
        bool orientation;

        InformationAboutWord(int x_, int y_, int length_, std::string word_, bool orientation_ = false):
        x(x_), y(y_), length(length_),word(word_), orientation(orientation_){}
    };

    struct OccupiedLetter
    {
        int x, y;
        OccupiedLetter(int x_, int y_): x(x_), y(y_){}
    };

    std::vector<std::vector<std::string>> field;
    std::vector<InformationAboutWord> InformationAboutWordVector;
    std::vector<OccupiedLetter> OccupiedLetterVector;
public:
    Field();
    ~Field();

    void AddAWordOnTheField(std::string word);

    void AddInformationAboutWord(int x, int y, int length, bool orientation, std::string word);
    void AddOccupiedLetter(int x, int y);
    bool InspectionOccupiedLetter(int x, int y);
    std::vector<std::vector<std::string>> Generation(std::vector<std::string> words);
    std::vector<std::vector<std::string>> OutputField();

//    int MaxXInfoField();
//    int MaxYInfoField();
//    int MinXInfoField();
//    int MinYInfoField();

};

#endif // FIELD_H

#include "field.h"
#include "playingfield.h"
#include "vocabulary.h"

void Field::InfoOccupiedLetter()
{
    OccupiedLetter *current = first_OcLet;

    while(current)
    {
        std::cout<<current->x<<" "<<current->y<<std::endl;
        current = current->next;
    }
}

void Field::PrintField()
{
    for(int i = 0; i < sizeField; i++)
    {
        for(int j = 0; j < sizeField; j++)
            std::cout<<field[i][j]<<" ";
        std::cout<<std::endl;
    }
}

void Field::PrintPlayingField()
{
    for(int i = 0; i < sizeField; i++)
    {
        for(int j = 0; j < sizeField; j++)
            std::cout<<playingField[i][j]<<" ";
        std::cout<<std::endl;
    }
}

void Field::PrintFieldM()
{
    for(int i = MinYInfoField(); i < MaxYInfoField(); i++)
    {
        for(int j = MinXInfoField(); j < MaxXInfoField(); j++)
            std::cout<<field[i][j]<<" ";
        std::cout<<std::endl;
    }
}

void Field::PrintPlayingFieldM()
{
    for(int i = MinYInfoField(); i < MaxYInfoField(); i++)
    {
        for(int j = MinXInfoField(); j < MaxXInfoField(); j++)
            std::cout<<playingField[i][j]<<" ";
        std::cout<<std::endl;
    }
}

void Vocabulary::Output()
{
    Vocabulary *current = first;
    while (current)
    {
        std::cout<<current->word<<std::endl;
        current = current->next;
    }

}

void Field::GetAllItemInfo()
{
    Information *current = first;
    while (current)
    {
        std::cout<<current->x<<" ";
        std::cout<<current->y<<" ";
        std::cout<<current->length<<" ";
        std::cout<<current->word<<"    ";
        std::cout<<current->numberWord<<" ";
        std::cout<<current->orientation<<std::endl;
        current = current->next;
    }
}

void Field::PrintInformation()
{
    Information *current = first;
    while (current)
    {
        std::cout<<current->numberWord<<". "<<current->word<<std::endl;
        current = current->next;
    }
}

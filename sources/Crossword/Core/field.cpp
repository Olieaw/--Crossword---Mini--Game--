#include "field.h"
#include "vocabulary.h"

Field::Field()
{
    sizeInfo = 0;
    first = last = nullptr;
    first_OcLet = last_OcLet = nullptr;

    field.resize(sizeField);
    for(int i = 0; i < sizeField; i++)
    {
        field[i].resize(sizeField);
        for(int j = 0; j < sizeField; j++)
            field[i][j] = "*";
    }

    playingField.resize(sizeField);
    for(int i = 0; i < sizeField; i++)
    {
        playingField[i].resize(sizeField);
        for(int j = 0; j < sizeField; j++)
            playingField[i][j] = "*";
    }
}

Field::~Field()
{
    Information *currentInf = nullptr;
    Information *nextInf = first;
    while(nextInf)
    {
        currentInf = nextInf;
        nextInf =nextInf->next;
        delete currentInf;
    }

    OccupiedLetter *currentOcLet = nullptr;
    OccupiedLetter *nextOcLet = first_OcLet;
    while(currentOcLet)
    {
        currentOcLet = nextOcLet;
        nextOcLet =nextOcLet->next;
        delete currentOcLet;
    }

    field.clear();
    playingField.clear();
}

void Field::AddInformation(int x, int y, int length, bool orientation, std::string word)
{
    sizeInfo++;
    Information *newItem = new Information(x, y, length, word, sizeInfo, orientation);
    if (!last)
    {
        first = newItem;
    }
    else
    {
        last->next = newItem;
    }
    last = newItem;
}

void Field::AddOccupiedLetter(int x, int y)
{
    OccupiedLetter *newItem = new OccupiedLetter(x, y);
    if(!last_OcLet)
    {
        first_OcLet = newItem;
    }
    else
    {
        last_OcLet->next = newItem;
    }
    last_OcLet = newItem;
}

void Field::FirstWordVerification(std::string word)
{
    for(int i = 0; i < sizeField; i++)
        for(int j = 0; j < sizeField; j++)
            if(field[i][j] == "*")
            {
                if((i + 1) == sizeField && (j + 1) == sizeField)
                {
                    int sizeWord = word.length();
                    for(int i = 0; i < sizeWord; i++)
                    {
                        field[sizeField / 2][sizeField / 2 + i - (sizeWord / 2)] = word[i];
                    }
                    AddInformation(sizeField / 2 - (sizeWord / 2), sizeField / 2, sizeWord, false , word);
                }
            }
            else
            {
                this->PrintNextWords(word);
                return;
            }
}

bool Field::InspectionOccupiedLetter(int x, int y)
{
    OccupiedLetter *intersection = first_OcLet;

    while(intersection)
        if((intersection->x != x) && (intersection->y != y)
                && (intersection->x + 1 != x) && (intersection->y + 1 != y)
                    &&(intersection->x - 1 != x) && (intersection->y - 1 != y))
        { intersection = intersection->next; }
        else
        { return false; }
    return true;
}

void Field::PrintNextWords(std::string word)
{
    Information *current = first;
    int sizeWord = word.length();

    while (current)
    {
        for(int i = 0; i < current->length; i++)
            for(int j = 0; j < sizeWord; j++)
            {
                if(current->word[i] == word[j] && current->word != word
                        && this->InspectionOccupiedLetter(current->x + i, current->y + j) == true)
                {
                    if(current->orientation == false)
                    {
                        for(int elem = 0; elem < sizeWord; elem++)
                        {
                            field[current->y - j +elem][current->x + i] = word[elem];
                        }

                        AddInformation(current->x + i, current->y - j, sizeWord, true, word);
                        AddOccupiedLetter(current->x + i, current->y);

                    }
                    else
                    {
                        for(int elem = 0; elem < sizeWord; elem++)
                        {
                            field[current->y + i][current->x - j + elem] = word[elem];
                        }

                        AddInformation(current->x - j, current->y + i, sizeWord, false, word);
                        AddOccupiedLetter(current->x, current->y + i);

                    }
                    return;

                }
            }
        current = current->next;
    }
}

void Field::AddCellsPlayingField()
{
    int number = 1;
    for(Information *current = first; current; current = current->next)
    {
        if(current->orientation == false)
            for(int i = 1; i < current->length; i++)
                playingField[current->y][current->x +i] = "-";
        else
            for(int i = 1; i < current->length; i++)
                playingField[current->y + i][current->x] = "|";
    }

    for(OccupiedLetter *current = first_OcLet; current; current = current->next)
        playingField[current->y][current->x] = "+";

    for(Information *current = first; current; current = current->next)
    {
        playingField[current->y][current->x] = std::to_string(number);
        number++;
    }
}

bool Field::EnterTheWord(int number, std::string word)
{
    for(Information *current = first; current; current = current->next)
        if(number == current->numberWord)
            if(word == current->word)
            {
                if(current->orientation == false)
                {
                    for(int i = 0; i < current->length; i++)
                        playingField[current->y][current->x +i] = current->word[i];
                }
                else
                {
                    for(int i = 0; i < current->length; i++)
                        playingField[current->y + i][current->x] = current->word[i];
                }
                return true;
            }
    return false;
}

int Field::MaxXInfoField()
{
    int maxX = 0;
    for(Information * current = first; current; current = current->next)
    {
        if(current->orientation == false)
            if((current->x + current->length) > maxX)
                maxX = (current->x + current->length);
    }
    return maxX;
}

int Field::MaxYInfoField()
{
    int maxY = 0;
    for(Information *current = first; current; current = current->next)
    {
        if(current->orientation != false)
            if((current->y + current->length) > maxY)
                maxY = (current->y + current->length);
    }
    return maxY;
}

int Field::MinXInfoField()
{
    int minX = sizeField;
    for(Information *current = first; current; current = current->next)
    {
        if(current->orientation == false)
            if(current->x < minX)
                minX = current->x;
    }
    return minX;
}

int Field::MinYInfoField()
{
    int minY = sizeField;
    for(Information *current = first; current; current = current->next)
    {
        if(current->orientation != false)
            if(current->y < minY)
                minY = current->y;
    }
    return minY;
}

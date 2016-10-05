#include "field.h"

Field::Field()
{
    field.resize(sizeField);
    for(int i = 0; i < sizeField; i++)
    {
        field[i].resize(sizeField);
        for(int j = 0; j < sizeField; j++)
            field[i][j] = " ";
    }
}

Field::~Field()
{
    field.clear();
    InformationAboutWordVector.clear();
    OccupiedLetterVector.clear();
}

void Field::AddInformationAboutWord(int x, int y, int length, bool orientation, std::string word)
{
    InformationAboutWordVector.push_back(InformationAboutWord(x, y,length, word, orientation));
}

void Field::AddOccupiedLetter(int x, int y)
{
    OccupiedLetterVector.push_back(OccupiedLetter(x, y));
}

void Field::AddAWordOnTheField(std::string word)
{
    int sizeWord = word.length();
    if(InformationAboutWordVector.size() == 0)
    {
        for(int i = 0; i < sizeWord; i++)
        {
            field[sizeField / 2][sizeField / 2 + i - (sizeWord / 2)] = word[i];
        }
        AddInformationAboutWord(sizeField / 2 - (sizeWord / 2), sizeField / 2, sizeWord, false , word);
    }
    else
    {
        for(std::vector<InformationAboutWord>::iterator infAboutWord = InformationAboutWordVector.begin(); infAboutWord<InformationAboutWordVector.end(); ++infAboutWord)
        {
            for(int i = 0; i < infAboutWord->length; i++)
                for(int j = 0; j < sizeWord; j++)
                {
                    if(infAboutWord->word[i] == word[j] && infAboutWord->word != word
                            && this->InspectionOccupiedLetter(infAboutWord->x + i, infAboutWord->y + j) == true)
                    {
                        if(infAboutWord->orientation == false)
                        {
                            for(int elem = 0; elem < sizeWord; elem++)
                            {
                                field[infAboutWord->y - j +elem][infAboutWord->x + i] = word[elem];
                            }

                            AddInformationAboutWord(infAboutWord->x + i, infAboutWord->y - j, sizeWord, true, word);
                            AddOccupiedLetter(infAboutWord->x + i, infAboutWord->y);

                        }
                        else
                        {
                            for(int elem = 0; elem < sizeWord; elem++)
                            {
                                field[infAboutWord->y + i][infAboutWord->x - j + elem] = word[elem];
                            }

                            AddInformationAboutWord(infAboutWord->x - j, infAboutWord->y + i, sizeWord, false, word);
                            AddOccupiedLetter(infAboutWord->x, infAboutWord->y + i);

                        }
                        return;
                    }
                }
        }
        return;
    }
}

bool Field::InspectionOccupiedLetter(int x, int y)
{
    std::vector<OccupiedLetter>::iterator intersection = OccupiedLetterVector.begin();

    while(intersection < OccupiedLetterVector.end())
        if((intersection->x != x) && (intersection->y != y)
                && (intersection->x + 1 != x) && (intersection->y + 1 != y)
                    &&(intersection->x - 1 != x) && (intersection->y - 1 != y))
        { intersection++; }
        else
        { return false; }
    return true;
}

std::vector<std::vector<std::string>> Field::Generation(std::vector<std::string> words)
{
    for(std::vector<std::string>::iterator it = words.begin(); it<words.end(); ++it)
        this->AddAWordOnTheField(*it);
    return field;
}

std::vector<std::vector<std::string>> Field::OutputField()
{
    return field;
}

/*int Field::MaxXInfoField()
{
    int maxX = 0;
    for(std::vector<InformationAboutWord>::iterator infAboutWord = InformationAboutWordVector.begin(); infAboutWord<InformationAboutWordVector.end(); ++infAboutWord)
    {
        if(infAboutWord->orientation == false)
            if((infAboutWord->x + infAboutWord->length) > maxX)
                maxX = (infAboutWord->x + infAboutWord->length);
    }
    return maxX;
}

int Field::MaxYInfoField()
{
    int maxY = 0;
    for(std::vector<InformationAboutWord>::iterator infAboutWord = InformationAboutWordVector.begin(); infAboutWord<InformationAboutWordVector.end(); ++infAboutWord)
    {
        if(infAboutWord->orientation != false)
            if((infAboutWord->y + infAboutWord->length) > maxY)
                maxY = (infAboutWord->y + infAboutWord->length);
    }
    return maxY;
}

int Field::MinXInfoField()
{
    int minX = sizeField;
    for(std::vector<InformationAboutWord>::iterator infAboutWord = InformationAboutWordVector.begin(); infAboutWord<InformationAboutWordVector.end(); ++infAboutWord)
    {
        if(infAboutWord->orientation == false)
            if(infAboutWord->x < minX)
                minX = infAboutWord->x;
    }
    return minX;
}

int Field::MinYInfoField()
{
    int minY = sizeField;
    for(std::vector<InformationAboutWord>::iterator infAboutWord = InformationAboutWordVector.begin(); infAboutWord<InformationAboutWordVector.end(); ++infAboutWord)
    {
        if(infAboutWord->orientation != false)
            if(infAboutWord->y < minY)
                minY = infAboutWord->y;
    }
    return minY;
}*/

#include "field.h"

void Field::NewField(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            //todo это разименование символа? зачем?
            field[i][j] = *"*"; //
    }
}
void Field::AddInformation(int x, int y, int length, bool orientation, char *word)
{
    Information *newItem = new Information(x, y, length, word, orientation);
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

void Field::GetAllItemInfo()
{

    Information *current = first;
    //todo не использовать вывод в консоль в бизнес логике
    while (current)
    {
        cout<<current->x<<" ";
        cout<<current->y<<" ";
        cout<<current->length<<" ";
        cout<<current->word<<" ";
        cout<<current->orientation<<endl;
        current = current->next;
    }

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

void Field::InfoOccupiedLetter()
{
    OccupiedLetter *current = first_OcLet;
    //todo не использовать вывод в консоль в бизнес логике
    while(current)
    {
        cout<<current->x<<" "<<current->y<<endl;
        current = current->next;
    }
}

void Field::FirstWordVerification(int size, char *word)
{ 
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(field[i][j] == *"*") //todo это разименование символа?
            {
                if((i + 1) == size && (j + 1) == size)
                {
                    this->PrintFirstWord(size, word);
                }
            }
            else
            {
                this->PrintNextWords(word);
                return;
            }
}

//todo метод добавляет только первое слово? почему нельзя все слова добавлять одним методом?
void Field::PrintFirstWord(int size, char *word)
{
    int sizeWord = strlen(word);
    for(int i = 0; i < sizeWord; i++)
    {
        field[size / 2][size / 2 + i - (sizeWord / 2)] = word[i];
    }
    AddInformation(size / 2 - (sizeWord / 2), size / 2, sizeWord, false , word);
}

void Field::PrintNextWords(char *word)
{
    Information *current = first;
    OccupiedLetter *cur = first_OcLet;
    int sizeWord = strlen(word);

    while (current)
    {
        for(int i = 0; i < current->length; i++)
            for(int j = 0; j < sizeWord; j++)
            {
                if(current->word[i] == word[j] && current->word != word)
                {
                    while(cur)
                        if((cur->x != current->x + i) && (cur->y != current->y + j))
                        { cur = cur->next; }
                        else
                        { return; }
                    //todo не обязательно писать == false
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

//todo в ядре не должно быть вывода в консоль
void Field::PrintField(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            cout<<field[i][j];
        cout<<endl;
    }
}

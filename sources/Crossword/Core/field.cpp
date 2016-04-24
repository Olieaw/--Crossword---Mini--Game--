#include "field.h"

void Field::NewField(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
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
    size++;
}

void Field::GetAllItemInfo()
{

    Information *current = first;
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

/*int Field::If(char *word, char *word2)
{
    int sizeWord = strlen(word);
    int sizeWord2 = strlen(word2);

    for(int num = 0; num < sizeWord; num++)
        for(int num2 = 0; num2 < sizeWord2; num2++)
            if(word[num] == word2[num2] && strcmp(word,word2) != 0)
            {
                return num;
            }
}*/

void Field::PrintWord(int size, char *word)
{
    Information *current = first;
    int sizeWord = strlen(word);

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            if(field[i][j] == *"*") //
            {
                if((i + 1) == size && (j + 1) == size)
                {
                    for(int numElem = 0; numElem < sizeWord; numElem++)
                    {
                        field[size / 2][size / 2 + numElem - (sizeWord / 2)] = word[numElem];
                    }
                    AddInformation(size / 2 - (sizeWord / 2), size / 2, sizeWord, false , word);
                }
            }
            else
            {
                while (current)
                {
                    for(int numElem = 0; numElem < current->length; numElem++)
                        for(int numElem2 = 0; numElem2 < sizeWord; numElem2++)
                        {
                            if(current->word[numElem] == word[numElem2]  && current->word != word)
                            {
                                if(current->orientation == false)
                                {
                                    for(int elem = 0; elem < sizeWord; elem++)
                                    {
                                        field[current->y - numElem2 +elem][current->x + numElem] = word[elem];
                                    }

                                    AddInformation(current->x + numElem, current->y - numElem2, sizeWord, true, word);
                                }
                                else
                                {
                                    for(int elem = 0; elem < sizeWord; elem++)
                                    {
                                        field[current->y + numElem][current->x - numElem2 + elem] = word[elem];
                                    }

                                    AddInformation(current->x - numElem2, current->y + numElem, sizeWord, false, word);
                                }
                                return;
                            }
                        }
                    current = current->next;
                }
            }
    }
}

void Field::Print(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            cout<<field[i][j];
        cout<<endl;
    }
}

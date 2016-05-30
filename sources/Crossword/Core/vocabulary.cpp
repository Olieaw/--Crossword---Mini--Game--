#include "vocabulary.h"

Vocabulary::~Vocabulary()
{
   Vocabulary *current = NULL;
   Vocabulary *next = first;
   while(next)
   {
       current = next;
       next =next->next;
       delete current;
   }
}

void Vocabulary::AddWord(std::string word)
{
    Vocabulary *newItem = new Vocabulary(word);
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

bool Vocabulary::Remove(std::string word)
{
    Vocabulary *prev = 0, *current = first;
    while (current)
    {
        if (!current->word.compare(word))
        {
            if(prev)
            {
                prev->next = current->next;
            }
            else
            {
                first = first->next;
            }
            if(current == last)
            {
                last = prev;
            }
            delete current;
            size--;
            return true;
        }
        else
        {
            prev =current;
            current = current->next;
        }
    }
    return false;
}

Field *Vocabulary::GenerationField()
{
    Vocabulary *vocabulary = first;
    Field *field = new Field;
    while (vocabulary)
        {
            field->FirstWordVerification(vocabulary->word);
            vocabulary = vocabulary->next;
        }
    field->AddCellsPlayingField();
    return field;
}

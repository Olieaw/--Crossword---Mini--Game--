#include "workwithvocabulary.h"

WorkWithVocabulary::~WorkWithVocabulary()
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

void WorkWithVocabulary::AddLast(int numer)
{
    Vocabulary *newItem = new Vocabulary(numer);
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

bool WorkWithVocabulary::Remove(int value)
{
    Vocabulary *prev = 0, *current = first;
    while (current)
    {
        if (current->numer == value)
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

string WorkWithVocabulary::GetAllItemInfo()
{
    stringstream stream;
    Vocabulary *current = first;
    while (current)
    {
        stream<<current->numer<<endl;
        current = current->next;
    }
    return stream.str();
}

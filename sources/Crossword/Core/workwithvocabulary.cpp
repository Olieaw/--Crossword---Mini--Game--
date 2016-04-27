#include "workwithvocabulary.h"
#include "field.h"

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

void WorkWithVocabulary::AddLast(char *word)
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

bool WorkWithVocabulary::Remove(char *value)
{
    Vocabulary *prev = 0, *current = first;
    while (current)
    {
        if (!strcmp(current->word,value))
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

void WorkWithVocabulary::Generation(int size)
{   //todo gener - не очень хорошее название для пременной
    Field *gener = new Field;
    Vocabulary *current = first;
    gener->NewField(size);
    while (current)
    {
        gener->FirstWordVerification(size, current->word);
        current = current->next;
    }
    gener->PrintField(size);
}

void WorkWithVocabulary::GetAllItemInfo()
{
    Vocabulary *current = first;
    while (current)
    {
        cout<<current->word<<endl;
        current = current->next;
    }

}

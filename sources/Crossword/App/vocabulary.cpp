#include "vocabulary.h"

Vocabulary::Vocabulary(const Vocabulary & src)
{
    VocElementCount = 0;
    first = last = NULL;
    AddLast(src);
}

Vocabulary::~Vocabulary()
{
    VocabularyStruct *current = NULL;
    VocabularyStruct *next = first;
    while (next)
    {
        current = next;
        next = next->next;
        delete current;
    }
}

Vocabulary::AddLast(const Vocabulary &src)
{
    for (VocabularyStruct *cur = src.first; cur; cur = cur->next)
        AddLast(cur->VocElement);
}

Vocabulary::AddLast(char VocElement)
{
    VocabularyStruct *newElement = new VocabularyStruct(VocElementCount);
    if (!last)
    {
        first = newElement;
    }
    else
    {
        last->next = newElement;
    }
    last = newElement;
    VocElementCount++;
}

Vocabulary::Remove(int value)
{
    VocabularyStruct *prev = 0, *current = first;
    while (current)
    {
        if (prev)
        {
            prev->next = current->next;
        }
        if (current == last)
        {
            last = prev;
        }
        delete current;
        VocElementCount--;
        return true;
    }
    else
    {
        prev = current;
        current = current->next;
    }
    return false;
}


















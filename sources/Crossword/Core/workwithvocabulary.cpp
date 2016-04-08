#include "workwithvocabulary.h"


WorkWithVocabulary::~WorkWithVocabulary()
{
    while (Head != 0) {
        Vocabulary *temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

void WorkWithVocabulary::Add(int numer)
{
    Vocabulary *temp = new(Vocabulary);
    temp->numer = numer;
    temp->Next = Head;
    Head = temp;
}

void WorkWithVocabulary::Show()
{
    Vocabulary *temp = Head;

    while(temp != 0)
    {
        cout<<temp->numer<<""<<endl;
        temp = temp->Next;
    }
}

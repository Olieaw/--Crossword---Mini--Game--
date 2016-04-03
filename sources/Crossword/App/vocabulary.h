#ifndef VOCABULARY_H
#define VOCABULARY_H

class Vocabulary
{
private:
    struct VocabularyStruct
    {
        //vector<char> VocElement[20];
        char  VocElement;
        VocabularyStruct *next;

        VocabularyStruct(char voc, VocabularyStruct *n)
        {
            VocElement = voc;
            next = n;
        }
    };

    int VocElementCount;
    Vocabulary *first;
    Vocabulary *last;

public:
    Vocabulary()
    {
        VocElementCount = 0;
        first = last = 0;
    }

    Vocabulary(const Vocabulary & src);

    ~Vocabulary();

    void AddLast(const Vocabulary & src);
    void AddLast(char VocElement);
    bool Remove(int n);
    void Insert(int n);

    int GetElementCount()
    {
        return VocElementCount;
    }

    string GetAllElementsInfo();
};

#endif // VOCABULARY_H

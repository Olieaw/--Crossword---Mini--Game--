#ifndef CROSSWORDAPI_H
#define CROSSWORDAPI_H


class CrosswordAPI
{

public:

    //размер поля
    void FieldSize(int x, int y);
    //добавить слово
    bool AddWord(char add_word);
    //удалить слово
    bool DeleteWord(char delete_word);
    //создать кроссворд
    void Create();
};

#endif // CROSSWORDAPI_H

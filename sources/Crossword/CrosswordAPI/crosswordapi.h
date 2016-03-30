#ifndef CROSSWORDAPI_H
#define CROSSWORDAPI_H


class CrosswordAPI
{

public:
    //размер поля
    void field_size(int x, int y);
    //добавить слово
    bool add_word(char add_word);
    //удалить слово
    bool delete_word(char delete_word);
    //создать кроссворд
    void create();
};

#endif // CROSSWORDAPI_H

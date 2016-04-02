#ifndef CORE_H
#define CORE_H


class Core
{

public:
    Core();

    //размер поля
    void FieldSize(int x, int y);
    //добавить слово
    bool AddWord(char add_word);
    //удалить слово
    bool DeleteWord(char delete_word);
    //создать кроссворд
    void Create();
};

#endif // CORE_H

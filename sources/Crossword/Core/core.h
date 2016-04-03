#ifndef CORE_H
#define CORE_H


class Core
{
private:

    int x, y;
    char add_word[15], delete_word[15];

public:

    //размер поля
    void FieldSize(int x, int y);
    //добавить слово
    bool AddWord(char* add_word);
    //удалить слово
    bool DeleteWord(char* delete_word);
    //создать кроссворд
    void Create();
};

#endif // CORE_H

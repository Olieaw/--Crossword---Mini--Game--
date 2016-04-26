#ifndef CROSSWORDAPI_H
#define CROSSWORDAPI_H

//todo Почему этот файл в APP? API должно быть в бибилиотеке.
//todo Почему нигде API не используется?
class CrosswordAPI
{

public:

    //todo лучше использовать JAVADOC
    /*
     *@brief размер поля
     */
    void FieldSize(int x, int y);
    //добавить слово
    //todo использовать string, а не сишные строки
    bool AddWord(char add_word);
    //удалить слово
    bool DeleteWord(char delete_word);
    //создать кроссворд
    void Create();
};

#endif // CROSSWORDAPI_H

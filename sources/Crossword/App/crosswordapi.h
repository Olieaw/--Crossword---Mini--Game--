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
    //todo метод добавляет слово, а получает один символ?
    bool AddWord(char add_word);
    //удалить слово
    //todo использовать string, а не сишные строки
    //todo метод удаляет слово, а получает один символ?
    bool DeleteWord(char delete_word);
    //создать кроссворд
    //todo может быть, createCrossword?
    void Create();
};

#endif // CROSSWORDAPI_H

#include "console.h"

Console::Console()
{

}

void Console::Menu()
{

    Vocalbulary *vocabulary = new Vocalbulary();
    Field *field = new Field();


    std::string word, str;
    int number = 0;

    while(1){
        std::cout << "1. Add word" << std::endl
                  << "2. Delete word" << std::endl
                  << "3. Show element" <<std::endl
                  << "4. Crossword generation" <<std::endl
                  << "0. Exit" << std::endl
                  << "-> ";

        std::cin>>str;
        try
        {
            number=std::stoi(str);
        }
        catch(std::exception &error)
        {
            number=100;
        }

        switch (number)
        {
        case 0:
            return;
            std::exit(0);
            break;
        case 1:
            std::cout<<"Print word"<<std::endl;
            std::cin>>word;
            vocabulary->AddWord(word);
            break;
        case 2:
            std::cout<<"Print word"<<std::endl;
            std::cin>>word;
            vocabulary->DelWord(word);
            break;
        case 3:
            std::cout<<"-----------------"<<std::endl;
            std::cout<<std::endl;
            PrintWords(vocabulary->Output());
            std::cout<<std::endl;
            std::cout<<"-----------------"<<std::endl;
            break;
        case 4:
            PrintField(field->Generation(vocabulary->Output()));
            break;
        default:
            std::cout<<"Invalid number! Try again"<<std::endl;
            std::cin.clear();
            getline(std::cin,str);
            break;
        }

    }
}

void Console::PrintWords(std::vector<std::string> str)
{
    for(std::vector<std::string>::iterator it = str.begin(); it<str.end(); ++it)
        std::cout<<*it<<std::endl;
}

void Console::PrintField(std::vector<std::vector<std::string>> field)
{
    int sizeField = field.size();
    for(int i = 0; i < sizeField; i++)
    {
        for(int j = 0; j < sizeField; j++)
            std::cout<<field[i][j]<<" ";
        std::cout<<std::endl;
    }
}

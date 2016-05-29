#include "consoleplaingfield.h"
#include "field.h"
#include "consoleapp.h"

void ConsolePlaingField::Console()
{
    Field *field = new Field;
    int number;
    std::string word;

    while(1)
    {
    field->PrintPlayingField();
    std::cout<<std::endl;

    field->PrintInformation();
    std::cout<<std::endl;

    std::cout<<"Print number: ";std::cin>>number;
    std::cout<<std::endl;
    std::cout<<"Print word: ";std::cin>>word;
    std::cout<<std::endl;

    if(field->EnterTheWord(number, word) == true)
        std::cout<<"Word is correct"<<std::endl;
    else
        std::cout<<"Word is not correct"<<std::endl;
    }

}

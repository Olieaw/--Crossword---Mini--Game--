#include "consoleapp.h"
#include "vocabulary.h"
#include "field.h"
#include "playingfield.h"
#include "consoleplaingfield.h"

void ConsoleApp::Menu()
{
    /*Field *qwe = new Field;

    qwe->FirstWordVerification("qwerbt");
    qwe->FirstWordVerification("wdfmnb");
    qwe->FirstWordVerification("mgfrgysr");
    qwe->FirstWordVerification("utqwf");
    qwe->FirstWordVerification("mhgnjh");
    qwe->FirstWordVerification("yjtlkfjbh");
    qwe->FirstWordVerification("hfjhnnhvc");
    qwe->FirstWordVerification("gcjgnbh");
    qwe->PrintFieldM();
    std::cout<<std::endl;
    qwe->PrintInformation();
    std::cout<<std::endl;
    qwe->AddCellsPlayingField();
    qwe->PrintPlayingFieldM();*/



    Vocabulary *vocabulary = new Vocabulary;
    ConsolePlaingField *consolePlaingField = new ConsolePlaingField;


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
            number=0;
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
            vocabulary->Remove(word);
            break;
        case 3:
            std::cout<<"-----------------"<<std::endl;
            std::cout<<std::endl;
            vocabulary->Output();
            std::cout<<std::endl;
            std::cout<<"-----------------"<<std::endl;
            break;
        case 4:
            consolePlaingField->Console(vocabulary->GenerationField());
            break;
        default:
            std::cout<<"Invalid number! Try again"<<std::endl;
            std::cin.clear();
            getline(std::cin,str);
            break;
        }

    }
}

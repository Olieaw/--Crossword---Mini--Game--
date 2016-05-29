#include "consoleapp.h"
#include "vocabulary.h"
#include "field.h"
#include "playingfield.h"
#include "consoleplaingfield.h"

void ConsoleApp::Menu()
{
    Field *qwe = new Field;

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
    qwe->PrintPlayingFieldM();



    /*Vocabulary *vocabulary = new Vocabulary;
    ConsolePlaingField *consolePlaingField = new ConsolePlaingField;
    Field *field = new Field;

    vocabulary->AddWord("qwerbt");
    vocabulary->AddWord("wdfmnb");
    vocabulary->GenerationField();
    field->PrintField();
    consolePlaingField->Console();
    field->PrintPlayingField();

    std::string word, str;
    int number_in_menu = 0;

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
            number_in_menu=std::stoi(str);
        }
        catch(std::exception &error)
        {
            number_in_menu=0;
        }

        switch (number_in_menu)
        {
        case 0:
            return;
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
            vocabulary->GenerationField();
            consolePlaingField->Console();
            break;
        default:
            std::cout << "Something goes wrong!" << std::endl;
            std::cout << std::endl;
            break;
        }

    }*/
}

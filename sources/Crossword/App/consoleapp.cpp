#include "consoleapp.h"
#include "workwithvocabulary.h"

void ConsoleApp::Menu()
{
    WorkWithVocabulary *add = new WorkWithVocabulary;
    int number_in_menu;
    int word;

    while(1){
        cout << "1. Add word" << endl
             << "2. Delete word" << endl
             << "3. Insert element" <<endl
             << "0. Exit" << endl
             << ">>> ";

        cin >> number_in_menu;
        if(cin.good())
        {
            switch (number_in_menu)
            {
            case 0:
                return;
                break;
            case 1:
                cout<<"Print word"<<endl;
                add->AddLast(4353);add->AddLast(542);add->AddLast(9461);add->AddLast(8764);
                cin>>word;
                add->AddLast(word);
                break;
            case 2:
                cin>>word;
                add->Remove(word);
                break;
            case 3:
                cout<< "------------------------" << endl
                    << endl
                    << add->GetAllItemInfo()
                    << endl
                    << "------------------------" << endl;
                break;
            default:
                cout << "Something goes wrong!" << endl;
                cin.clear();
                cout << endl;
                break;
            }
        }
        else
        {
            cout << "Error! Input a number." << endl ;
            cin.clear();
            cout << endl;
            Menu();
        }
    }
}

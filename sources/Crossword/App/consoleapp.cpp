#include "consoleapp.h"
#include "workwithvocabulary.h"
#include "field.h"

void ConsoleApp::Menu()
{
    const int size = 20;
    int num = 0;
    WorkWithVocabulary *add = new WorkWithVocabulary;
    int number_in_menu = 0;
    char word[size];
    while(1){
        cout << "1. Add word" << endl
             << "2. Delete word" << endl
             << "3. Insert element" <<endl
             << "4. Crossword generation" <<endl
             << "0. Exit" << endl
             << "-> ";

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
                cin>>word;
                add->AddLast(word);
                num++;
                break;
            case 2:
                cout<<"Print word"<<endl;
                cin>>word;
                if(add->Remove(word)==true)
                    cout<<"Delete word"<<endl;
                else
                    cout<<"Delete is not word"<<endl;
                break;
            case 3:
                cout<<"-----------------"<<endl;
                cout<<endl;
                add->GetAllItemInfo();
                cout<<endl;
                cout<<"-----------------"<<endl;
                break;
            case 4:
                add->Generation(size);
                return;
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
            cout << "Error! Input a number." << endl;
            cin.clear();
            cout << endl;
            Menu();
        }
    }
}

#include "consoleapp.h"
#include "workwithvocabulary.h"
#include "logic.h"
#include "field.h"

void ConsoleApp::Menu()
{
    WorkWithVocabulary *add = new WorkWithVocabulary;
    Field *q = new Field;

    char word[20]= "wdsssscffff";
    char word2[20]= "thfdj";
    char word3[20]= "ghcjgf";
    char word4[20]= "gevv";
    char word5[20]= "vvvvvvv";
    add->AddLast(word);
    add->AddLast(word2);

    q->NewField(20);
    q->PrintWord(20, word);
    q->Print(20);
    cout<<endl<<endl;
    q->PrintWord(20, word2);
    q->Print(20);
    cout<<endl<<endl;
    q->PrintWord(20, word3);
    q->Print(20);
    cout<<endl<<endl;
    q->PrintWord(20, word4);
    q->Print(20);
    cout<<endl<<endl;
    q->PrintWord(20, word5);
    q->Print(20);
    cout<<endl<<endl;
    q->GetAllItemInfo();



    /*WorkWithVocabulary *add = new WorkWithVocabulary;
    int number_in_menu = 0;
    char word[20];
    while(1){
        cout << "1. Add word" << endl
             << "2. Delete word" << endl
             << "3. Insert element" <<endl
             << "0. Exit" << endl
             << "--> ";

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
    }*/
}

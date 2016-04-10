#include "consoleapp.h"
#include "workwithvocabulary.h"

void ConsoleApp::Menu()
{
    WorkWithVocabulary add;
    ConsoleApp app;
    int number_in_menu;
    int word;

    cout << "1. Add word" << endl
         << "2. Delete word(does not work)" << endl
         << "0. Exit" << endl
         << ">>> ";

    cin >> number_in_menu;

    if(cin.good())
    {
        switch (number_in_menu)
        {
        case 0:
            break;
        case 1:
            cout<<"Print word"<<endl;
            //cin>>word;
            add.AddLast(1);
            add.AddLast(2);
            add.AddLast(3);
            cout<<add.GetAllItemInfo();
            app.Menu();
            break;
        default:
            cout << "Something goes wrong!" << endl;
            cin.clear();
            cout << endl;
            Menu();
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

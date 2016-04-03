#include "consoleapp.h"
#include "vocabulary.h"

void ConsoleApp::Menu()
{
    int number_in_menu;

    cout << "1. Add word" << endl
         << "2. Delete word(does not work)" << endl
         << "0. Exit" << endl;

    cin >> number_in_menu;

    if(cin.good())
    {
        switch (number_in_menu)
        {
        case 0:
            break;
        case 1:
            cout << endl;
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

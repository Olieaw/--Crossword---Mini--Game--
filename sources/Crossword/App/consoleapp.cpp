#include "consoleapp.h"
#include "workwithvocabulary.h"
#include "logic.h"

void ConsoleApp::Menu()
{
    Logic r;
    r.Read();
    r.Print();
    r.If();




    /*while(1){
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

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

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
    }*/
}

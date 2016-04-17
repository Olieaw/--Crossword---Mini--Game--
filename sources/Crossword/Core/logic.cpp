#include "logic.h"

void Logic::Read()
{
    ifstream voc("../words.txt", ios_base::in);

    voc>>this->numberWord;
    for(int i = 0; i < 3;i++){
    Vocabulary.push_back(word);
    voc>>Vocabulary.at(i).word;
    }

    voc.close();

    for(int i = 0; i < 3;i++){
        Vocabulary.at(i).lenght = strlen(Vocabulary.at(i).word);
    }
}

void Logic::If()
{
    for(int num = 0; num < this->numberWord; num++)
        for(int num2 = 0; num2 < this->numberWord; num2++)
            for(int i = 0; i < Vocabulary.at(num).lenght; i++)
                for(int j = 0; j < Vocabulary.at(num2).lenght; j++)
                {
                    if(Vocabulary.at(num).word[i] == Vocabulary.at(num2).word[j] &&
                            Vocabulary.at(num).word != Vocabulary.at(num2).word)
                    {
                        if(Vocabulary.at(num).orientation == Vocabulary.at(num2).orientation &&
                                Vocabulary.at(num).orientation == false)
                            Vocabulary.at(num2).orientation = true;
                        else
                            Vocabulary.at(num2).orientation = false;

                        cout<<Vocabulary.at(num).word<<"---"<<Vocabulary.at(num2).word
                            <<endl<<Vocabulary.at(num2).orientation<<endl;
                    }
                }

}

void Logic::Print()
{
    cout<<this->numberWord<<endl<<endl;

    for(int i = 0; i < 3;i++)
    cout<<Vocabulary.at(i).word<<endl<<Vocabulary.at(i).lenght<<endl<<Vocabulary.at(i).word[0]<<endl;
}

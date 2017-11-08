/*
  Hangman
  (c) Afaan Bilal

  Play hangman!
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

const int numWords = 50;
string wordlist[numWords];

string input;
size_t f;
int sel = 0;
int maxTries = 10;
int tries = 0;

void cls();
void display();
bool checkIfWon();

int main()
{
    ifstream file("hangman.txt");
    if(file.is_open())
    {
        for(int i = 0; i < numWords; ++i)
        {
            file >> wordlist[i];
        }
    }

    srand(time(NULL));
    sel = rand() % numWords;
    char c = ' ';
    display();
    cout << endl << "\tEnter an alphabet: ";
    c = _getch();
    while (c != '.')
    {
        c = toupper(c);
        f = input.find(c);
        
        if (f == string::npos)
        {
            input.push_back(c);
            
            if (wordlist[sel].find(c) == string::npos)
            {
                tries++;
                if (tries >= maxTries)
                {
                    display();
                    cout << endl << "\t\tSorry! You have lost!" << endl << endl;
                    cout << "\t\tThe word was " << wordlist[sel] << endl << endl;
                    break;
                }
            }
            
            display();
            
            if (checkIfWon())
            {
                cout << endl << "\t\tCongratulations! You have won!" << endl << endl;
                break;
            }
        }
        else
        {
            cout << endl << "\tAlphabet already entered." << endl;
        }

        cout << endl << "\tEnter an alphabet: ";
        c = _getch();
    }
}

void cls()
{
    system("@cls || clear");
}

void drawHangman()
{
    cout << endl;
    switch (tries)
    {
        case 10: 
                 cout << "\t\t       YOU KILLED ME!" << endl;
                 cout << "\t\t\t   _________ " << endl;
        case 9:  cout << "\t\t\t     |      |" << endl;
        case 8:  cout << "\t\t\t    ---     |" << endl;
        case 7:  cout << "\t\t\t   |   |    |" << endl;
        case 6:  cout << "\t\t\t    ---     |" << endl;
        case 5:  cout << "\t\t\t ----|----  |" << endl;
        case 4:  cout << "\t\t\t     |      |" << endl;
        case 3:  cout << "\t\t\t     |      |" << endl;
        case 2:  cout << "\t\t\t    ---     |" << endl;
        case 1:  cout << "\t\t\t   /   \\    |" << endl;
                 cout << "\t\t\t            |" << endl;
                 cout << "\t\t\t____________|" << endl;
    }
    cout << endl << endl;
}

void display()
{
    cls();
    
    cout << endl << "\t\t\t" << "HANGMAN" << endl << endl;
    cout << "\thttps://github.com/AfaanBilal/hangman" << endl << endl;
    
    drawHangman();

    cout << "\tPress '.' to exit." << endl;
    cout << "\tTries left: " << (maxTries - tries) << endl << endl;
    cout << "\t\t    ";

    for (int i = 0; i < wordlist[sel].length(); i++)
    {
        f = input.find(wordlist[sel][i]);
        if (f == string::npos)
            cout << "_" << " ";
        else
            cout << wordlist[sel][i] << " ";
    }

    cout << endl;
}

bool checkIfWon()
{
    for (int i = 0; i < wordlist[sel].length(); i++)
    {
        if (input.find(wordlist[sel][i]) == string::npos)
            return false;
    }

    return true;
}

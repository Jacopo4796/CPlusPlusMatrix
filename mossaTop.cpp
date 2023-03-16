#include <iostream>

using namespace std;

void stampa(char *tab)
{
    for (int i = 0; i < 9; i++)
    {
        cout << tab[i] << " ";
        if (i == 2 || i == 5 || i == 8) // alla fine di ogni riga (3x3) vai a capo
        {
            cout << endl;
        }
    }

    cout << endl;
    cout << endl;
    cout << endl;
}

int main()
{
    int risultato = -1;
    char vuoto = '_';

    // inizializzo la tab
    char tab[9];
    for (int i = 0; i < 9; i++)
    {
        tab[i] = vuoto;
    }
    stampa(tab);

/*
    X _ _
    X O _
    _ _ _
*/

    tab[1] = 'X';
    tab[2] = 'X';
    tab[4] = 'O';
    

    stampa(tab);

    // QUI LAVORO

    int combinazioni[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

    for (int i = 0; i < 8; i++) // due X su 0 e 1 
    {

        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];

        bool condizione = a == b && c == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][2];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 0 e 2 
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][1]];

        bool condizione = a == b && c == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][1];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 1 e 2
    {

        char a = tab[combinazioni[i][1]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][0]];

        bool condizione = a == b && c == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][0];
        }
    }

    cout << "risultato ottenuto: " << risultato << " | risultato atteso: 0" << endl;
}
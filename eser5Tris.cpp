#include <iostream>
using namespace std;

const char VUOTO = '-';

// Crea logica nelle mosse del COMPUTER
int mossaPensata(char *tab)
{
    int risultato = -1;
    int combinazioni[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};
    // Prima controllo se il giocatore può vincere
    // Se il giocatore può vincere lo blocco
    for (int i = 0; i < 8; i++) // Due 'X' su 0 e 1
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];
        bool condizione = a == b && c == VUOTO && a == 'X';
        if (condizione)
        {
            risultato = combinazioni[i][2];
        }
    }
    for (int i = 0; i < 8; i++) // Due 'X' su 0 e 2
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][1]];
        bool condizione = a == b && c == VUOTO && a == 'X';
        if (condizione)
        {
            risultato = combinazioni[i][1];
        }
    }
    for (int i = 0; i < 8; i++) // Due 'X' su 1 e 2
    {
        char a = tab[combinazioni[i][1]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][0]];
        bool condizione = a == b && c == VUOTO && a == 'X';
        if (condizione)
        {
            risultato = combinazioni[i][0];
        }
    }
    // Controllo se il computer può vincere
    // Se ci sono due O metto il terzo
    for (int i = 0; i < 8; i++) // Due 'O' su 0 e 1
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];
        bool condizione = a == b && c == VUOTO && a == 'O';
        if (condizione)
        {
            risultato = combinazioni[i][2];
        }
    }
    for (int i = 0; i < 8; i++) // Due 'O' su 0 e 2
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][1]];
        bool condizione = a == b && c == VUOTO && a == 'O';
        if (condizione)
        {
            risultato = combinazioni[i][1];
        }
    }
    for (int i = 0; i < 8; i++) // Due 'O' su 1 e 2
    {
        char a = tab[combinazioni[i][1]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][0]];
        bool condizione = a == b && c == VUOTO && a == 'O';
        if (condizione)
        {
            risultato = combinazioni[i][0];
        }
    }
    if (risultato == -1)
    {
        risultato = random() % 9;
    }
    return risultato;
}

// Restituisce: 1 = Win; 0 = Continue; -1 = Tie
int isWinner(char *arr)
{
    int combinazioni[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};
    for (int i = 0; i < 8; i++)
    {
        int a = arr[combinazioni[i][0]];
        int b = arr[combinazioni[i][1]];
        int c = arr[combinazioni[i][2]];
        if (a != VUOTO && a == b && b == c)
        {
            return 1;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == VUOTO)
        {
            return 0; // C'è ancora spazio
        }
    }
    return -1;
}

// Stampa la tabella
void stampa(char *tabella)
{
    for (int i = 0; i < 9; i++)
    {
        cout << tabella[i] << " ";
        if (i == 2 || i == 5 || i == 8) // Alla fine di ogni riga (3x3) vai a capo
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
    // Inizializzo la tabella
    char tabella[9];
    for (int i = 0; i < 9; i++)
    {
        tabella[i] = VUOTO;
    }
    stampa(tabella);
    bool xIsNext = true; // Gestisce il turno
    while (true)         // I turni del gioco
    {
        int mossa;

        if (!xIsNext) // COMPUTER
        {
            mossa = mossaPensata(tabella);
        }
        else // UTENTE
        {
            cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
            cin >> mossa;
            mossa--;
            while (tabella[mossa] != VUOTO || (!(0 <= mossa && mossa < 9))) // Controllo 2 condizioni (valido e VUOTO)
            {
                cout << "Non puoi inserire qui" << endl;
                cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
                cin >> mossa;
                mossa--;
            }
        }
        // Se arriva qui è perchè l'utente ha inserito un numero corretto
        xIsNext ? tabella[mossa] = 'X' : tabella[mossa] = 'O'; // Se true mette 'X' altrimenti metti 'O'
        stampa(tabella);
        if (isWinner(tabella) == 1)
        {
            cout << "Ha vinto " << (xIsNext ? 'X' : 'O') << endl;
            break;
        }
        else if (isWinner(tabella) == -1)
        {
            cout << "Pareggio" << endl;
            // Reset game
            for (int i = 0; i < 9; i++)
            {
                tabella[i] = VUOTO;
            }
            xIsNext = true;
            stampa(tabella);
        }
        else if (isWinner(tabella) == 0)
        {
            xIsNext = !xIsNext; // Cambio giocatore
        }
        else
        {
            cout << "Errore nella funzione isWinner" << endl;
        }
    }
}
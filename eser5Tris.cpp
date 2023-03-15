#include <iostream>

using namespace std;

// 0 1 2 
// 3 4 5 
// 6 7 8 

// 1 per la vittoria
// 0 per continuare la partita
// -1 per il pareggio
int isWinner(char *arr)
{
    for(int i = 0; i < 7; i += 3) // Righe (indice max riga 6)
    {
        if(arr[i] != '-')
        {
            if((arr[i] == arr[i + 1]) && (arr[i + 1] == arr[i + 2]))
            {
                return 1;
            }
        } 
    }
    for(int i = 0; i < 3; i++) // Colonne (indice max colonna 2)
    {
        if(arr[i] != '-')
        {
            if((arr[i] == arr[i + 3]) && (arr[i] == arr[i + 6]))
            {
                return 1;
            }
        }
    }
    if(((arr[0] != '-') && (arr[0] == arr[4]) && (arr[0] == arr[8])) || ((arr[2] != '-') && (arr[2] == arr[4]) && (arr[2] == arr[6]))) // Diagonali
    {
        return 1;
    }
    for(int i = 0; i < 9; i++)
    {
        if(arr[i] == '-') // 
        {
            return 0;
        }
    }
    return -1;
}

void stampa(char *a)
{
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
        if (i == 2 || i == 5 || i == 8)
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
    char vuoto = '-';
    // inizializzo la tabella
    char tabella[9];
    for (int i = 0; i < 9; i++)
    {
        tabella[i] = vuoto;
    }
    stampa(tabella);
    bool xIsNext = true; // gestisce il turno
    while (true)         // i turni del gioco
    {
        int mossa;
        cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
        cin >> mossa;
        mossa--; // per capirci ;)
        while (tabella[mossa] != vuoto || (!(0 <= mossa && mossa < 9))) // controllo 2 condizioni (valido e vuoto)
        {
            cout << "Non puoi inserire qui" << endl;
            cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
            cin >> mossa;
            mossa--;
        }
        // se sono arrivato qui è solo perchè l'utente ha inserito un numero corretto
        xIsNext ? tabella[mossa] = 'X' : tabella[mossa] = 'O'; // se è vero metti X altrimenti metti O
        stampa(tabella);
        if (isWinner(tabella) == 1)
        {
            cout << "Hai vinto " << (xIsNext ? 'X' : 'O') << endl;
            break;
        }
        else if (isWinner(tabella) == -1)
        {
            cout << "Pareggio" << endl;
            // reset del gioco
            for (int i = 0; i < 9; i++)
            {
                tabella[i] = vuoto;
            }
            xIsNext = true;
            stampa(tabella);
        }
        else if (isWinner(tabella) == 0)
        {
            xIsNext = !xIsNext; // cambio giocatore
        }
        else
        {
            cout << "Errore nella funzione isWinner" << endl;
        }
    }
}
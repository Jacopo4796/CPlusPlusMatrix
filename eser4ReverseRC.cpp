/* Crea una matrice quadrata piena di numeri random
0-9.
- Stampa la matrice invertendo le righe
- Stampa la matrice invertendo le colonne
- Stampa la matrice trasposta
*/
#include <iostream>
using namespace std;

int main()
{
    int righe = 5;
    int colonne = 5;
    //            Y       X
    //           LAT     LONG
    int matrice[righe][colonne];
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrice[i][j] = rand() % 10;
        }
    }
    cout << "    ";
    for (int i = 0; i < colonne; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    int trattini = colonne * 2 + 4;
    for (int i = 0; i < trattini; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < righe; i++)
    {
        cout << i << "|  ";
        for (int j = 0; j < colonne; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }   
}
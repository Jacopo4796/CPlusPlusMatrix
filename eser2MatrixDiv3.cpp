/* Crea una matrice quadrata piena di numeri random
da 0 a 9. Crea poi il vettore risultato prendendo i 
soli numeri divisibile per 3 dalla matrice iniziale. */

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
    cout << "\n I numeri divisibili per 3 presenti nella matrice sono: \n";
    int contali = 0;
    for(int i = 0; i < righe; i++)
    {
        for(int j = 0; j < colonne; j++)
        {
            if(matrice[i][j] % 3 == 0 && matrice[i][j] != 0)
            {
                cout << matrice[i][j] << ", ";
                contali++;
            }
        }
    } 
    cout << "\n Per un totale di " << contali << " valori";
}
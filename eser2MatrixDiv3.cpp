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
            matrice[i][j] = rand() % 10; // Riempio la matrice di numeri randomici
        }
    }
    cout << "    ";
    for (int i = 0; i < colonne; i++) // Scorro l'indice delle colonne
    {
        cout << i << "  "; // Stampo l'indice delle colonne
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < righe; i++) // Scorro l'indice delle righe
    {
        cout << i << "   "; // Stampo l'indice delle righe
        for (int j = 0; j < colonne; j++)
        {
            cout << matrice[i][j] << "  "; // Stampo i numeri randomici dentro la matrice
        }
        cout << endl;
    }
    int contali = 0; // Creo un contatore
    cout << "\n I numeri divisibili per 3 presenti nell'array sono: ";
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if (matrice[i][j] % 3 == 0 && matrice[i][j] != 0) // Se nella matrice sono presenti numeri divisibile per tre e sono diversi da zero
            { 
                contali++;  // Incremento il contatore                 
            }
        }
    }
    int arrayDiv[contali]; // Creo un'array
    int k = 0; // Creo l'indice dell'array
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if (matrice[i][j] % 3 == 0 && matrice[i][j] != 0) // Se nella matrice sono presenti numeri divisibile per tre e sono diversi da zero
            { 
                arrayDiv[k] = matrice[i][j]; 
                k++;             
            }
        }
    }
    for(int i = 0; i < contali; i++)
    {
        cout << arrayDiv[i] << " ";
    }
}    
/* Crea una matrice quadrata piena di numeri random
0-9.
- Stampa la matrice invertendo le righe
- Stampa la matrice invertendo le colonne
- Stampa la matrice trasposta
*/
#include <iostream>
using namespace std;
const int RIGHE = 5;
const int COLONNE = 5;
// Riempio la matrice di numeri randomici
void riempiMatrix(int matrice[][COLONNE])
{
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            matrice[i][j] = rand() % 10; 
        }
    }
}
// Stampo i numeri randomici dentro la matrice
void stampaMatrix(int matrice[][COLONNE])
{
    cout << "    ";
    for (int i = 0; i < COLONNE; i++) // Scorro l'indice delle colonne
    {
        cout << i << "  "; // Stampo l'indice delle colonne
    }
    cout << endl;
    for (int i = 0; i < RIGHE; i++) // Scorro l'indice delle righe
    {
        cout << i << "   "; // Stampo l'indice delle righe
        for (int j = 0; j < COLONNE; j++)
        {
            cout << matrice[i][j] << "  "; 
        }
        cout << endl;
    }
}

int main()
{
    //            Y       X
    //           LAT     LONG
    int matrice[RIGHE][COLONNE];
    riempiMatrix(matrice); // Richiamo la funzione per riempire la matrice
    stampaMatrix(matrice); // Richiamo la funzione per stampare la matrice
    cout << endl;
    cout << "La matrice con le righe invertite è: \n";
    for (int i = RIGHE - 1; i >= 0; i--) // Scorro le righe partendo dall'ultima
    {
        for (int j = 0; j < COLONNE; j++) // Scorro le colonne
        {
            cout << matrice[i][j] << " "; // Stampo la matrice con le righe invertite
        }
        cout << endl;
    }
    cout << endl;
    cout << "La matrice con le colonne invertite è: \n";
    for (int i = 0; i < RIGHE; i++) // Scorro le righe
    {
        for (int j = COLONNE - 1; j >= 0; j--) // Scorro le colonne partendo dall'ultima
        {
            cout << matrice[i][j] << " "; // Stampo la matrice con le colonne invertite 
        }
        cout << endl;
    }
    cout << endl;
    cout << "La matrice trasposta è: \n";
    for (int i = 0; i < RIGHE; i++) // Scorro le righe
    {
        for (int j = 0; j < COLONNE; j++) // Scorro le colonne
        {
            cout << matrice[j][i] << " "; // Stampo la matrice invertendo l'indice delle righe con quello delle colonne
        }
        cout << endl;
    }
}
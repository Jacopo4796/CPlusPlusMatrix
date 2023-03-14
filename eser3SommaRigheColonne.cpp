#include <iostream>
using namespace std;

int main()
{
    int righe = 10;
    int colonne = 10;
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
        cout << i << "   "; // Stampo l'indice delle colonne
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < righe; i++) // Scorro l'indice delle righe
    {
        int sumRighe = 0; 
        cout << i << "   "; // Stampo l'indice delle righe
        for (int j = 0; j < colonne; j++)
        { 
            sumRighe += matrice[i][j];
            cout << matrice[i][j] << "   "; // Stampo i numeri randomici dentro la matrice 
        }
        cout << "| " << sumRighe;
        cout << endl;
    }
    cout << endl;
    cout << "   ";
    for (int i = 0; i < colonne; i++) // Scorro le colonne
    {
        
        int sumColonne = 0;             // Imposto il contatore a zero
        for (int j = 0; j < righe; j++) // Scorro le righe
        {
            sumColonne += matrice[j][i]; // Sommo le colonne della matrice
        }      
        cout << sumColonne << "  "; // Stampo la somma delle colonne della matrice
    }
}

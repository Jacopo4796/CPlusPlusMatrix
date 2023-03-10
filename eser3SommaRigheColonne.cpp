/*
INPUT
5  3  1  2
4  1  4  1
2  2  5  1
5  6  7  2

OUTPUT
5  3  1  2  | 11
4  1  4  1  | 10
2  2  5  1  | 10
5  6  7  2  | 20
----------------
16 12 17 6
*/

#include <iostream>
using namespace std;

int main()
{
    int righe [5];
    int colonne [5];
    int lungRighe = sizeof(righe) / sizeof(righe[0]);
    int lungColonne = sizeof(colonne) / sizeof(colonne[0]);
    //            Y       X
    //           LAT     LONG
    int matrice[lungRighe][lungColonne];
    for (int i = 0; i < lungRighe; i++)
    {
        for (int j = 0; j < lungColonne; j++)
        {
            matrice[i][j] = rand() % 10;
        }
    }
    cout << "    ";
    for (int i = 0; i < lungColonne; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    int trattini = lungColonne * 2 + 4;
    for (int i = 0; i < trattini; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < lungRighe; i++)
    {
        cout << i << "|  ";
        for (int j = 0; j < lungColonne; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    } 
    
}
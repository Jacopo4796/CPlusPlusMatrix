#include <iostream>
using namespace std;

int main()
{
    int numAlunni = 4; // Numero degli alunni;
    int numProve = 3; // Numero delle prove
    int votazione[numAlunni][numProve]; // Dichiarazione della matrice votazione

    for(int i = 0; i < numAlunni; i++) // Riempio la matrice delle votazione
    {
        for(int j = 0; j < numProve; j++)
        {
            cout << "Inserire il voto dello studente " << i + 1 << " alla prova " << j + 1 << ": ";
            cin >> votazione[i][j]; // Inserisco il voto dello studente 
        }
    }
    cout << endl;
    cout << "Votazioni degli alunni: \n";
    for(int i = 0; i < numAlunni; i++) // Scorro tutti gli alunni
    {
        cout << "Alunno " << i + 1 << ": "; // Stampo l'alunno
        for(int j = 0; j < numProve; j++) // Scorro tutte le prove
        {
            cout << votazione[i][j] << ", "; // Stampo la votazione 
        }
        cout << endl;
    }
}
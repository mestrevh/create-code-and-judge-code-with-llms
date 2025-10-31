/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matrix(3, vector<int>(3));
    while (true) {
        bool isTriangularSuperior = true, isTriangularInferior = true;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> matrix[i][j];
            }
        }
        
        if (cin.eof()) break; // Finaliza se não houver mais entradas
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (matrix[i][j] != 0) {
                    if (i > j) isTriangularSuperior = false;     // Verifica triangular superior
                    if (i < j) isTriangularInferior = false;     // Verifica triangular inferior
                }
            }
        }

        if (isTriangularSuperior) {
            cout << "Por baixo" << endl;
        } else if (isTriangularInferior) {
            cout << "Por cima" << endl;
        } else {
            cout << "Nao pode atravessar" << endl;
        }

        cin.ignore(); // Ignora a linha em branco
    }
    return 0;
}

/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    char carro;
    int ano;

    double trans[3][3] = {
        {0.5, 0.25, 0.25},
        {0.0, 0.0, 1.0},
        {1.0, 0.0, 0.0}
    };

    while (cin >> carro >> ano) {
        if (ano <= 2005 || (carro != 'S' && carro != 'P' && carro != 'G')) {
            cout << "Entrada inválida" << endl;
        } else {
            double estadoAtual[3] = {1.0, 0.0, 0.0};
            for (int i = 2005; i < ano; ++i) {
                double novoEstado[3] = {0.0, 0.0, 0.0};
                for (int j = 0; j < 3; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        novoEstado[j] += estadoAtual[k] * trans[k][j];
                    }
                }
                for (int j = 0; j < 3; ++j) {
                    estadoAtual[j] = novoEstado[j];
                }
            }

            if (carro == 'S') {
                cout << "Probabilidade de ter um Sedan em " << ano << ": " << fixed << setprecision(2) << estadoAtual[0] * 100 << "%" << endl;
            } else if (carro == 'P') {
                cout << "Probabilidade de ter um Palio em " << ano << ": " << fixed << setprecision(2) << estadoAtual[1] * 100 << "%" << endl;
            } else if (carro == 'G') {
                cout << "Probabilidade de ter um Gol em " << ano << ": " << fixed << setprecision(2) << estadoAtual[2] * 100 << "%" << endl;
            }
        }
    }

    return 0;
}

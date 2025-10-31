/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    int par_points = 0, impar_points = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum_coords = i + j;
            if (sum_coords % 2 == 0) { // coordenadas pares
                for (int k = 0; k < words[i].size(); ++k) {
                    if (k % 2 == 0) { // posições pares
                        par_points += words[i][k];
                    }
                }
            } else { // coordenadas ímpares
                for (int k = 0; k < words[i].size(); ++k) {
                    if (k % 2 != 0) { // posições ímpares
                        impar_points += words[i][k];
                    }
                }
            }
        }
    }

    if (par_points > impar_points) {
        cout << "Os pares venceram com " << par_points << " pontos!" << endl;
    } else if (impar_points > par_points) {
        cout << "Os impares venceram com " << impar_points << " pontos!" << endl;
    } else {
        cout << "Tivemos um empate em " << par_points << " pontos!" << endl;
    }

    return 0;
}

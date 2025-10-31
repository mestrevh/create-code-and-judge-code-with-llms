/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    float trans[3][3] = {
        {0.5, 0.25, 0.25}, // De S para: S, P, G
        {0.0, 0.0, 1.0},   // De P para: S, P, G
        {1.0, 0.0, 0.0}    // De G para: S, P, G
    };

    vector<string> carros = {"S", "P", "G"};
    vector<char> indices = {'S', 'P', 'G'};

    string entrada;
    while (getline(cin, entrada)) {
        char carro = entrada[0];
        int ano = stoi(entrada.substr(2));

        if (ano <= 2005 || (carro != 'S' && carro != 'P' && carro != 'G')) {
            cout << "Entrada inválida\n";
            continue;
        }

        int anosDeTroca = ano - 2005;
        vector<float> estadoAtual(3, 0.0);
        estadoAtual[0] = 1.0;

        for (int i = 0; i < anosDeTroca; ++i) {
            vector<float> proximoEstado(3, 0.0);
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    proximoEstado[k] += estadoAtual[j] * trans[j][k];
                }
            }
            estadoAtual = proximoEstado;
        }

        int index = find(indices.begin(), indices.end(), carro) - indices.begin();
        cout << fixed << setprecision(2);
        cout << "Probabilidade de ter um " << carros[index] << " em " << ano << ": "
             << estadoAtual[index] * 100 << "%\n";
    }

    return 0;
}

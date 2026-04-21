/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char carro;
    long long ano;

    const double trans[3][3] = {
        {0.5, 0.25, 0.25},
        {0.0, 0.0, 1.0},
        {1.0, 0.0, 0.0}
    };

    auto idx = [&](char c) -> int {
        if (c == 'S') return 0;
        if (c == 'P') return 1;
        if (c == 'G') return 2;
        return -1;
    };

    while (cin >> carro >> ano) {
        int id = idx(carro);
        if (id == -1 || ano <= 2005) {
            cout << "Entrada inválida\n";
            continue;
        }

        double estadoAtual[3] = {1.0, 0.0, 0.0};

        long long steps = ano - 2005;
        for (long long k = 0; k < steps; k++) {
            double nextEstado[3] = {0.0, 0.0, 0.0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    nextEstado[j] += estadoAtual[i] * trans[i][j];
                }
            }
            for (int j = 0; j < 3; j++) estadoAtual[j] = nextEstado[j];
        }

        double prob = estadoAtual[id] * 100.0;
        string nome;
        if (id == 0) nome = "Sedan";
        else if (id == 1) nome = "Palio";
        else nome = "Gol";

        cout << "Probabilidade de ter um " << nome << " em " << ano << ": ";
        cout.setf(std::ios::fixed);
        cout << setprecision(2) << prob << "%\n";
        cout.unsetf(std::ios::fixed);
    }

    return 0;
}
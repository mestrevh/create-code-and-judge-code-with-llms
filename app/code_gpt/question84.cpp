/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int O, D, T;
    vector<vector<int>> autoM(4, vector<int>(4, 0)), camM(4, vector<int>(4, 0)), busM(4, vector<int>(4, 0));
    int beloHorizonte = 0, onibusBrasilia = 0;

    while (true) {
        cin >> O >> D >> T;
        if (O == 0 && D == 0 && T == 0) break;

        if (T == 1) autoM[O - 1][D - 1]++;
        else if (T == 2) camM[O - 1][D - 1]++;
        else if (T == 3) busM[O - 1][D - 1]++;
        
        if (O == 1) beloHorizonte++;
        if (O == 4 && (D == 2 || D == 4)) onibusBrasilia += busM[3][D - 1];
    }

    cout << "Automovel:\n";
    for (const auto &row : autoM) {
        for (const auto &val : row) cout << val << ' ';
        cout << '\n';
    }
    cout << "Caminhao:\n";
    for (const auto &row : camM) {
        for (const auto &val : row) cout << val << ' ';
        cout << '\n';
    }
    cout << "Onibus:\n";
    for (const auto &row : busM) {
        for (const auto &val : row) cout << val << ' ';
        cout << '\n';
    }

    cout << "Origem Belo Horizonte: " << beloHorizonte << '\n';
    cout << "Onibus: Brasilia - Petropolis ou Barbacena: " << onibusBrasilia << '\n';

    return 0;
}

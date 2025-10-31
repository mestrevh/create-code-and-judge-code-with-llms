/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string analisarCidade(int n, vector<vector<char>>& cidade) {
    bool temGuardasNasPares = false, temPopularesNasImpares = false;
    int suspeitosPorLinha[100] = {0};
    bool temInimigoDiagonal = false;
    int quantidadeInimigos = 0, quantidadeSuspeitos = 0, quantidadeGuardas = 0;

    for (int i = 0; i < n; i++) {
        quantidadeGuardas += static_cast<int>(count(cidade[i].begin(), cidade[i].end(), 'g'));
        quantidadeInimigos += static_cast<int>(count(cidade[i].begin(), cidade[i].end(), 'i'));
        quantidadeSuspeitos += static_cast<int>(count(cidade[i].begin(), cidade[i].end(), 's'));
        
        for (int j = 0; j < n; j++) {
            if (cidade[i][j] == 'g' && j % 2 == 0) temGuardasNasPares = true;
            if (cidade[i][j] == 'p' && j % 2 != 0) temPopularesNasImpares = true;
            if (i == j && cidade[i][j] == 'i') temInimigoDiagonal = true; // Diagonal principal
            if (i + j == n - 1 && cidade[i][j] == 'i') temInimigoDiagonal = true; // Diagonal secundária

            if (cidade[i][j] == 's') suspeitosPorLinha[i]++;
        }
    }

    if (temGuardasNasPares && temPopularesNasImpares) return "BRANCO";
    for (int i = 0; i < n; i++) {
        if (suspeitosPorLinha[i] >= 2) return "AMARELO";
    }
    if (temInimigoDiagonal) return "LARANJA";
    if (quantidadeInimigos + quantidadeSuspeitos > quantidadeGuardas) return "VERMELHO";
    return "TRANSPARENTE";
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> cidade(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cidade[i][j];
        }
    }

    cout << analisarCidade(n, cidade) << endl;
    return 0;
}

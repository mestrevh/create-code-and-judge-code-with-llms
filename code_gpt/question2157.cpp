/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <set>

bool linhasIguais(const std::vector<int>& a, const std::vector<int>& b) {
    return a == b;
}

int main() {
    std::vector<std::vector<int>> matriz;
    std::string linha;
    
    while (getline(std::cin, linha) && linha != "acabou") {
        std::istringstream iss(linha);
        std::vector<int> linhaVec((std::istream_iterator<int>(iss)), std::istream_iterator<int>());
        matriz.push_back(linhaVec);
    }
    
    int n = matriz.size();
    if (n == 0 || matriz[0].size() != n) {
        std::cout << "O determinante de uma matriz só existe para matrizes quadradas." << std::endl;
        return 0;
    }

    // Verificação de linhas iguais
    std::set<std::vector<int>> linhasUnicas;
    for (const auto& l : matriz) {
        if (linhasUnicas.count(l)) {
            std::cout << "Determinante zero." << std::endl;
            return 0;
        }
        linhasUnicas.insert(l);
    }

    // Verificação de colunas iguais
    for (int j = 0; j < n; j++) {
        std::vector<int> coluna;
        for (int i = 0; i < n; i++) {
            coluna.push_back(matriz[i][j]);
        }

        if (linhasUnicas.count(coluna)) {
            std::cout << "Determinante zero." << std::endl;
            return 0;
        }
    }

    // Verificação de linhas ou colunas com todos elementos iguais a zero
    for (const auto& l : matriz) {
        if (std::all_of(l.begin(), l.end(), [](int x) { return x == 0; })) {
            std::cout << "Determinante zero." << std::endl;
            return 0;
        }
    }

    for (int j = 0; j < n; j++) {
        std::vector<int> coluna;
        for (int i = 0; i < n; i++) {
            coluna.push_back(matriz[i][j]);
        }

        if (std::all_of(coluna.begin(), coluna.end(), [](int x) { return x == 0; })) {
            std::cout << "Determinante zero." << std::endl;
            return 0;
        }
    }

    std::cout << "Determinante diferente de zero." << std::endl;
    return 0;
}

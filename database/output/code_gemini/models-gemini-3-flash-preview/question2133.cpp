/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

/**
 * Função recursiva para inverter a ordem dos elementos em um vetor de strings.
 * Complexidade de tempo: O(N), onde N é o número de linhas.
 * Complexidade de espaço: O(N) devido à pilha de recursão.
 */
void inverterOrdem(vector<string>& v, int i, int j) {
    if (i >= j) return;
    swap(v[i], v[j]);
    inverterOrdem(v, i + 1, j - 1);
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> pagina;
    string linha;

    // Leitura das linhas feita no main conforme restrição
    while (getline(cin, linha)) {
        pagina.push_back(linha);
    }

    // Processamento recursivo para inverter a ordem das linhas
    if (!pagina.empty()) {
        inverterOrdem(pagina, 0, (int)pagina.size() - 1);
    }

    // Impressão feita no main conforme restrição
    for (size_t i = 0; i < pagina.size(); ++i) {
        cout << pagina[i] << "\n";
    }

    return 0;
}
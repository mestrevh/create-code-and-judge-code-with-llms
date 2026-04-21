/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

std::vector<int> ordenar(std::vector<int> lista) {
    int n = (int)lista.size();
    for (int i = 1; i < n; ++i) {
        int chave = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > chave) {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = chave;
    }
    return lista;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> entrada(7);
    for (int i = 0; i < 7; ++i) {
        if (!(std::cin >> entrada[i])) break;
    }

    std::vector<int> resultado = ordenar(entrada);

    std::cout << "[";
    for (int i = 0; i < 7; ++i) {
        std::cout << resultado[i] << (i < 6 ? ", " : "");
    }
    std::cout << "]" << std::endl;

    return 0;
}
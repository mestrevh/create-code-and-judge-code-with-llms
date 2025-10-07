/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> fila1(n), fila2(m);

    for (int i = 0; i < n; ++i) std::cin >> fila1[i];
    for (int i = 0; i < m; ++i) std::cin >> fila2[i];

    std::vector<int> filaResultado;
    int i = 0, j = 0;

    if (k == 1) {
        filaResultado.push_back(fila1[i++]);
        while (i < n || j < m) {
            if (j < m) filaResultado.push_back(fila2[j++]);
            if (i < n) filaResultado.push_back(fila1[i++]);
        }
    } else {
        filaResultado.push_back(fila2[j++]);
        while (i < n || j < m) {
            if (i < n) filaResultado.push_back(fila1[i++]);
            if (j < m) filaResultado.push_back(fila2[j++]);
        }
    }

    for (int pessoa : filaResultado) {
        std::cout << pessoa << std::endl;
    }

    return 0;
}

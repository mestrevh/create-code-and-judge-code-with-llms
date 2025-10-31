/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

struct Consulta {
    int inicio;
    int fim;
};

bool comparaConsultas(const Consulta& a, const Consulta& b) {
    if (a.fim != b.fim) {
        return a.fim < b.fim;
    }
    return a.inicio < b.inicio;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<Consulta> consultas(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> consultas[i].inicio >> consultas[i].fim;
    }

    std::sort(consultas.begin(), consultas.end(), comparaConsultas);

    int contador = 1;
    int ultimo_fim = consultas[0].fim;

    for (int i = 1; i < n; ++i) {
        if (consultas[i].inicio >= ultimo_fim) {
            contador++;
            ultimo_fim = consultas[i].fim;
        }
    }

    std::cout << contador << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

struct Camiseta {
    std::string nome;
    std::string cor;
    char tamanho;
};

bool compareCamisetas(const Camiseta& a, const Camiseta& b) {
    if (a.cor != b.cor) {
        return a.cor < b.cor;
    }
    if (a.tamanho != b.tamanho) {
        return a.tamanho > b.tamanho;
    }
    return a.nome < b.nome;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    bool first_case = true;

    while (std::cin >> N && N != 0) {
        if (!first_case) {
            std::cout << "\n";
        }
        first_case = false;

        std::vector<Camiseta> camisetas(N);
        std::cin.ignore(); 

        for (int i = 0; i < N; ++i) {
            std::getline(std::cin, camisetas[i].nome);
            std::cin >> camisetas[i].cor >> camisetas[i].tamanho;
            std::cin.ignore();
        }

        std::sort(camisetas.begin(), camisetas.end(), compareCamisetas);

        for (const auto& camiseta : camisetas) {
            std::cout << camiseta.cor << " " << camiseta.tamanho << " " << camiseta.nome << "\n";
        }
    }

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Camiseta {
    std::string nome;
    std::string cor;
    std::string tamanho;
};

bool comparar(const Camiseta &a, const Camiseta &b) {
    if (a.cor != b.cor)
        return a.cor < b.cor;
    if (a.tamanho != b.tamanho)
        return a.tamanho > b.tamanho;
    return a.nome < b.nome;
}

int main() {
    while (true) {
        int N;
        std::cin >> N;
        if (N == 0) break;
        std::cin.ignore();

        std::vector<Camiseta> camisetas(N);
        for (int i = 0; i < N; ++i) {
            std::getline(std::cin, camisetas[i].nome);
            std::string detalhes;
            std::getline(std::cin, detalhes);
            camisetas[i].cor = detalhes.substr(0, detalhes.find(' '));
            camisetas[i].tamanho = detalhes.substr(detalhes.find(' ') + 1);
        }

        std::sort(camisetas.begin(), camisetas.end(), comparar);

        for (const auto &c : camisetas) {
            std::cout << c.cor << " " << c.tamanho << " " << c.nome << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}

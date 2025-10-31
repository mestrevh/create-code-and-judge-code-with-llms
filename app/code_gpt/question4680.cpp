/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Criança {
    std::string nome;
    int pontuação;

    Criança(std::string n, int p) : nome(n), pontuação(p) {}
};

int main() {
    int N;
    std::cin >> N;
    std::vector<Criança> crianças;

    for (int i = 0; i < N; i++) {
        std::string nome;
        int pontuaçãoAntiga, ótimas, boas, ruins, péssimas;
        std::cin >> nome >> pontuaçãoAntiga >> ótimas >> boas >> ruins >> péssimas;

        int pontuaçãoFinal = pontuaçãoAntiga + (ótimas * 5) + (boas * 3) + (ruins * -3) + (péssimas * -5);
        crianças.emplace_back(nome, pontuaçãoFinal);
    }

    std::sort(crianças.begin(), crianças.end(), [](const Criança &a, const Criança &b) {
        if (a.pontuação == b.pontuação) return a.nome < b.nome;
        return a.pontuação < b.pontuação;
    });

    for (const auto &criança : crianças) {
        std::cout << criança.nome << " " << criança.pontuação << "\n";
    }

    return 0;
}

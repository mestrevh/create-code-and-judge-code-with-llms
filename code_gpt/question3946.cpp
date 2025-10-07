/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Clube {
    std::string nome;
    float valorMercado;
    int grandesJogadores;
    int titulos;
    bool temNeymar;
    bool flamengo2019;
    float pontos;
};

float calcularPontuacao(Clube &clube) {
    return clube.valorMercado + clube.grandesJogadores * 100 + clube.titulos * 2000 +
           (clube.temNeymar ? 10000 : 0) + (clube.flamengo2019 ? 20000 : 0);
}

bool compararClube(const Clube &a, const Clube &b) {
    return a.pontos > b.pontos;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Clube> clubes(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> clubes[i].nome;
        std::cin >> clubes[i].valorMercado >> clubes[i].grandesJogadores >> clubes[i].titulos;
        std::string neymar, flamengo;
        std::cin >> neymar >> flamengo;
        clubes[i].temNeymar = (neymar == "sim");
        clubes[i].flamengo2019 = (flamengo == "sim");
        clubes[i].pontos = calcularPontuacao(clubes[i]);
    }

    std::sort(clubes.begin(), clubes.end(), compararClube);

    for (const auto &clube : clubes) {
        std::cout << clube.nome << " " << std::fixed << std::setprecision(2) << clube.pontos << std::endl;
    }
    return 0;
}

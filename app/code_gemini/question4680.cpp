/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Crianca {
    std::string nome;
    int pontuacao;
};

bool compararCriancas(const Crianca& a, const Crianca& b) {
    if (a.pontuacao != b.pontuacao) {
        return a.pontuacao > b.pontuacao;
    }
    return a.nome < b.nome;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Crianca> criancas;
    for (int i = 0; i < n; ++i) {
        std::string nome;
        int p_anterior, otimas, boas, ruins, pessimas;
        std::cin >> nome >> p_anterior >> otimas >> boas >> ruins >> pessimas;

        int pontuacao_final = p_anterior + (otimas * 5) + (boas * 3) - (ruins * 3) - (pessimas * 5);
        criancas.push_back({nome, pontuacao_final});
    }

    std::sort(criancas.begin(), criancas.end(), compararCriancas);

    for (const auto& crianca : criancas) {
        std::cout << crianca.nome << " " << crianca.pontuacao << "\n";
    }

    return 0;
}

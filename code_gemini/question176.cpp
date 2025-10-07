/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Aluno {
    std::string nome;
    int habilidade;
};

bool comparaAlunos(const Aluno& a, const Aluno& b) {
    return a.habilidade > b.habilidade;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, T;
    std::cin >> N >> T;

    std::vector<Aluno> alunos(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> alunos[i].nome >> alunos[i].habilidade;
    }

    std::sort(alunos.begin(), alunos.end(), comparaAlunos);

    std::vector<std::vector<std::string>> times(T);
    for (int i = 0; i < N; ++i) {
        times[i % T].push_back(alunos[i].nome);
    }

    for (int i = 0; i < T; ++i) {
        std::cout << "Time " << i + 1 << "\n";
        std::sort(times[i].begin(), times[i].end());
        for (const std::string& nome : times[i]) {
            std::cout << nome << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}

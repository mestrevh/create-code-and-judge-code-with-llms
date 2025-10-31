/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

struct Aluno {
    std::string nome;
    int idade;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Aluno> alunos(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> alunos[i].nome;
        std::cin >> alunos[i].idade;
    }

    for (int i = 0; i < n; ++i) {
        if (alunos[i].idade <= 14) {
            std::cout << alunos[i].nome << '\n';
            std::cout << alunos[i].idade << '\n';
        }
    }

    for (int i = 0; i < n; ++i) {
        if (alunos[i].idade > 14) {
            std::cout << alunos[i].nome << '\n';
            std::cout << alunos[i].idade << '\n';
        }
    }

    return 0;
}

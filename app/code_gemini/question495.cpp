/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_alunos = 0;
    int alunos_turma;

    for (int i = 0; i < 7; ++i) {
        std::cin >> alunos_turma;
        total_alunos += alunos_turma;
    }

    int total_grampos = total_alunos * 4;
    int total_caixas = (total_grampos + 29) / 30;

    std::cout << total_grampos << std::endl;
    std::cout << total_caixas << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int num_questoes;
    std::cin >> num_questoes;
    std::string gabarito;
    std::cin >> gabarito;
    int num_alunos;
    std::cin >> num_alunos;
    for (int i = 0; i < num_alunos; ++i) {
        std::string respostas_aluno;
        std::cin >> respostas_aluno;
        int nota = 0;
        for (int j = 0; j < num_questoes; ++j) {
            if (respostas_aluno[j] == gabarito[j]) {
                nota++;
            }
        }
        std::cout << nota << "\n";
    }
    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int total_alunos = 0;

    for (int i = 0; i < n; ++i) {
        int alunos_turma;
        std::cin >> alunos_turma;
        while (alunos_turma > 40) {
            std::cout << "O numero de alunos nao pode ser maior do que 40" << std::endl;
            std::cin >> alunos_turma;
        }
        total_alunos += alunos_turma;
    }

    if (n > 0) {
        double media = static_cast<double>(total_alunos) / n;
        int media_arredondada = round(media);
        std::cout << media_arredondada << std::endl;
    }

    return 0;
}

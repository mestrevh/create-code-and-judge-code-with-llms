/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Aluno {
    std::string nome;
    double nota;
    int idade;
};

void trocar(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const int NUM_ALUNOS = 5;
    Aluno alunos[NUM_ALUNOS];
    double notas_ordenadas[NUM_ALUNOS];

    for (int i = 0; i < NUM_ALUNOS; ++i) {
        std::cin >> alunos[i].nome;
        std::cin >> alunos[i].nota >> alunos[i].idade;
        notas_ordenadas[i] = alunos[i].nota;
    }

    for (int i = 0; i < NUM_ALUNOS - 1; ++i) {
        for (int j = 0; j < NUM_ALUNOS - i - 1; ++j) {
            if (notas_ordenadas[j] > notas_ordenadas[j + 1]) {
                trocar(notas_ordenadas[j], notas_ordenadas[j + 1]);
            }
        }
    }

    for (int i = 0; i < NUM_ALUNOS; ++i) {
        alunos[i].nota = notas_ordenadas[i];
    }

    for (int i = 0; i < NUM_ALUNOS; ++i) {
        std::cout << alunos[i].nome << " "
                  << std::fixed << std::setprecision(2) << alunos[i].nota << " "
                  << alunos[i].idade << std::endl;
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string gabarito;
    std::cin >> gabarito;

    int aluno;
    int total_alunos = 0;
    int aprovados = 0;
    std::vector<int> frequencia_notas(11, 0);

    while (std::cin >> aluno && aluno != 9999) {
        total_alunos++;
        std::string respostas;
        std::cin >> respostas;

        int nota = 0;
        for (int i = 0; i < 10; ++i) {
            if (gabarito[i] == respostas[i]) {
                nota++;
            }
        }

        if (nota >= 6) {
            aprovados++;
        }

        frequencia_notas[nota]++;

        std::cout << aluno << " " << std::fixed << std::setprecision(1) << (double)nota << std::endl;
    }

    if (total_alunos > 0) {
        double percentual_aprovacao = (double)aprovados / total_alunos * 100.0;
        std::cout << std::fixed << std::setprecision(1) << percentual_aprovacao << "%" << std::endl;

        int maior_frequencia = 0;
        int nota_mais_frequente = 0;
        for (int i = 0; i <= 10; ++i) {
            if (frequencia_notas[i] > maior_frequencia) {
                maior_frequencia = frequencia_notas[i];
                nota_mais_frequente = i;
            }
        }
        std::cout << std::fixed << std::setprecision(1) << (double)nota_mais_frequente << std::endl;

    } else {
        std::cout << std::fixed << std::setprecision(1) << 0.0 << "%" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << 0.0 << std::endl;
    }

    return 0;
}

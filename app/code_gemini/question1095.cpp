/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int filosofiaAprovados = 0;
    int totalAprovados = 0;
    int sociologiaReprovadosMaiores = 0;
    int minIdade = std::numeric_limits<int>::max();
    std::string nomeMaisJovem;
    bool anyStudentProcessed = false;

    double media;
    std::string nome;
    int idade;
    char curso;

    while (std::cin >> media && media >= 0) {
        anyStudentProcessed = true;
        std::cin >> nome >> idade >> curso;

        if (idade < minIdade) {
            minIdade = idade;
            nomeMaisJovem = nome;
        }

        if (media >= 70) {
            totalAprovados++;
            if (curso == 'f') {
                filosofiaAprovados++;
            }
        } else {
            if (curso == 's' && idade >= 18) {
                sociologiaReprovadosMaiores++;
            }
        }
    }

    std::cout << "Quantidade de aprovados em filosofia : " << filosofiaAprovados << std::endl;

    if (anyStudentProcessed) {
        std::cout << "O nome da pessoa mais jovem : " << nomeMaisJovem << std::endl;
    }

    std::cout << "Quantidade de aprovados : " << totalAprovados << std::endl;
    std::cout << "Quantidade pessoas maiores de idade nao aprovadas em sociologia : " << sociologiaReprovadosMaiores << std::endl;

    return 0;
}

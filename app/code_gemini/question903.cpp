/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char gabarito[10] = {'A', 'B', 'C', 'D', 'E', 'E', 'D', 'C', 'B', 'A'};
    char resposta;
    int nota = 0;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Insira a resposta do aluno para a pergunta " << i + 1 << ":" << std::endl;
        std::cin >> resposta;
        if (resposta == gabarito[i]) {
            nota++;
        }
    }

    std::cout << "Nota do aluno: " << nota << std::endl;

    return 0;
}

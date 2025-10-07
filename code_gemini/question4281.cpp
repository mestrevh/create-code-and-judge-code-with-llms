/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string nome_aluno;
    double altura_aluno;

    std::string nome_mais_alto;
    double maior_altura = 0.0;

    while (std::cin >> nome_aluno && nome_aluno != "parar") {
        std::cin >> altura_aluno;
        if (altura_aluno > maior_altura) {
            maior_altura = altura_aluno;
            nome_mais_alto = nome_aluno;
        }
    }

    int altura_cm = static_cast<int>(maior_altura * 100);

    std::cout << "O aluno mais alto tem " << altura_cm << " cm e se chama " << nome_mais_alto << "." << std::endl;

    return 0;
}

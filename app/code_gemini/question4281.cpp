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

    std::string nome;
    double altura;

    std::string nome_mais_alto;
    double altura_maxima = 0.0;

    while (std::cin >> nome) {
        if (nome == "parar") {
            break;
        }
        std::cin >> altura;
        if (altura > altura_maxima) {
            altura_maxima = altura;
            nome_mais_alto = nome;
        }
    }

    int altura_cm = altura_maxima * 100;

    std::cout << "O aluno mais alto tem " << altura_cm << " cm e se chama " << nome_mais_alto << "." << std::endl;

    return 0;
}

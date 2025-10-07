/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string nome, alunoMaisAlto;
    double altura, alturaMaisAlta = 0.0;

    while (true) {
        std::getline(std::cin, nome);
        if (nome == "parar") break;

        std::cin >> altura;
        std::cin.ignore(); // para ignorar o '\n' após a entrada da altura

        if (altura > alturaMaisAlta) {
            alturaMaisAlta = altura;
            alunoMaisAlto = nome;
        }
    }

    std::cout << "O aluno mais alto tem " << static_cast<int>(alturaMaisAlta * 100) << " cm e se chama " << alunoMaisAlto << "." << std::endl;
    return 0;
}

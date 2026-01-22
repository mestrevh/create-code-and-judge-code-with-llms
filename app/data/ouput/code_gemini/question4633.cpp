/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int idade;
    int soma_idades = 0;
    int contador = 0;

    while (std::cin >> idade && idade != 0) {
        soma_idades += idade;
        contador++;
    }

    if (contador > 0) {
        int media = soma_idades / contador;
        std::cout << "media de idade da turma: " << media << std::endl;

        if (media >= 0 && media <= 25) {
            std::cout << "jovem" << std::endl;
        } else if (media >= 26 && media <= 60) {
            std::cout << "adulta" << std::endl;
        } else {
            std::cout << "idosa" << std::endl;
        }
    }

    return 0;
}

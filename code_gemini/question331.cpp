/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

struct Usuario {
    int idade;
    std::string nome;
    char sexo;
    char estado_civil;
    int num_amigos;
    int num_fotos;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Usuario> banco_de_dados(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> banco_de_dados[i].idade;
        std::cin >> banco_de_dados[i].nome;
        std::cin >> banco_de_dados[i].sexo;
        std::cin >> banco_de_dados[i].estado_civil;
        std::cin >> banco_de_dados[i].num_amigos;
        std::cin >> banco_de_dados[i].num_fotos;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << "Idade: " << banco_de_dados[i].idade << std::endl;
        std::cout << "Nome: " << banco_de_dados[i].nome << std::endl;
        std::cout << "Sexo: " << banco_de_dados[i].sexo << std::endl;
        std::cout << "Estado Civil: " << banco_de_dados[i].estado_civil << std::endl;
        std::cout << "Numero de amigos: " << banco_de_dados[i].num_amigos << std::endl;
        std::cout << "Numero de fotos: " << banco_de_dados[i].num_fotos << std::endl;

        if (i < n - 1) {
            std::cout << std::endl;
        }
    }

    return 0;
}

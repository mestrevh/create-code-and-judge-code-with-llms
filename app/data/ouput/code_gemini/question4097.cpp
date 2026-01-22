/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct usuario {
    int idade;
    std::string nome;
    char sexo;
    char estado_civil;
    int amigos;
    int fotos;
};

void cadastraUsuario(struct usuario users[], int posicao) {
    std::cin >> users[posicao].idade;
    std::cin >> users[posicao].nome;
    std::cin >> users[posicao].sexo;
    std::cin >> users[posicao].estado_civil;
    std::cin >> users[posicao].amigos;
    std::cin >> users[posicao].fotos;
}

void imprimeUsuario(struct usuario *user) {
    std::cout << "Idade: " << user->idade << std::endl;
    std::cout << "Nome: " << user->nome << std::endl;
    std::cout << "Sexo: " << user->sexo << std::endl;
    std::cout << "Estado Civil: " << user->estado_civil << std::endl;
    std::cout << "Numero de amigos: " << user->amigos << std::endl;
    std::cout << "Numero de fotos: " << user->fotos << std::endl;
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cout << "Digite a quantidade de usuarios:" << std::endl;
    std::cin >> n;

    if (n > 0) {
        usuario* users = new usuario[n];

        for (int i = 0; i < n; ++i) {
            std::cout << "Digite os dados do usuario " << i + 1 << ":" << std::endl;
            cadastraUsuario(users, i);
        }

        for (int i = 0; i < n; ++i) {
            imprimeUsuario(&users[i]);
        }

        delete[] users;
    }

    return 0;
}

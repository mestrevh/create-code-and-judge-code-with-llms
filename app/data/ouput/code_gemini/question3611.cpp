/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Contato {
    std::string nomeCompleto;
    std::string numero;
    int codigoVinculo;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Contato> contatos;
    contatos.reserve(n);
    for (int i = 0; i < n; ++i) {
        Contato novoContato;
        std::getline(std::cin, novoContato.nomeCompleto);
        std::cin >> novoContato.numero;
        std::cin >> novoContato.codigoVinculo;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        contatos.push_back(novoContato);
    }

    std::string nomePesquisa;
    while (std::cin >> nomePesquisa && nomePesquisa != "#") {
        bool encontrou = false;
        bool primeiroDaBusca = true;

        for (const auto& contato : contatos) {
            size_t pos = contato.nomeCompleto.find(' ');
            std::string primeiroNome = (pos == std::string::npos) ?
                                       contato.nomeCompleto :
                                       contato.nomeCompleto.substr(0, pos);

            if (primeiroNome == nomePesquisa) {
                encontrou = true;
                if (!primeiroDaBusca) {
                    std::cout << "\n";
                }

                std::cout << "Nome: " << contato.nomeCompleto << "\n";
                std::cout << "Numero: " << contato.numero << "\n";
                std::cout << "Vinculo: ";
                switch (contato.codigoVinculo) {
                    case 1:
                        std::cout << "Familia\n";
                        break;
                    case 2:
                        std::cout << "Faculdade\n";
                        break;
                    case 3:
                        std::cout << "Amigo\n";
                        break;
                }
                primeiroDaBusca = false;
            }
        }

        if (!encontrou) {
            std::cout << nomePesquisa << " nao foi cadastrado\n";
        }
    }

    return 0;
}

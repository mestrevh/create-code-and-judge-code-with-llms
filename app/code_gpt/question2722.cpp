/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

struct Bandido {
    std::string nome;
    int forca_defesa;
    Bandido* proximo;
};

void interrogar(Bandido* inicio, int fi) {
    Bandido* atual = inicio;
    Bandido* anterior = nullptr;
    bool todosPresos = true;

    while (atual) {
        if (fi >= atual->forca_defesa) {
            if (atual->proximo) {
                std::cout << "Conseguimos interrogar " << atual->nome << ", que nos entregou " << atual->proximo->nome << ".\n";
                anterior = atual;
                atual = atual->proximo;
            } else {
                std::cout << "Agora sim, com a confissao de " << atual->nome << ", prendemos todos os canalhas.\n";
                return;
            }
        } else {
            std::cout << "Droga, a busca acabou em " << atual->nome << ".\n";
            return;
        }
        if (anterior) {
            anterior->proximo = atual;
        }
    }
}

int main() {
    int fi;
    std::cin >> fi;
    
    Bandido* inicio = nullptr;
    Bandido* atual = nullptr;

    std::string nome;
    int forca_defesa;

    while (std::cin >> nome && nome != "Fim") {
        std::cin >> forca_defesa;
        
        Bandido* novo = new Bandido{nome, forca_defesa, nullptr};
        if (!inicio) {
            inicio = novo;
            atual = novo;
        } else {
            atual->proximo = novo;
            atual = novo;
        }
    }

    interrogar(inicio, fi);
    return 0;
}

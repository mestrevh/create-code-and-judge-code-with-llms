/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Celular {
    string nome;
    double preco;
    double nota;
    double custoBeneficio;

    Celular(string n, double p, double no) : nome(n), preco(p), nota(no) {
        custoBeneficio = no / p;
    }
};

int main() {
    double orcamento;
    cin >> orcamento;
    vector<Celular> celulares;

    for (int i = 0; i < 3; ++i) {
        string nome;
        double preco, nota;
        cin >> nome >> preco >> nota;
        celulares.emplace_back(nome, preco, nota);
    }

    Celular* melhorCelular = nullptr;

    for (auto& celular : celulares) {
        if (celular.preco <= orcamento) {
            if (!melhorCelular || 
                celular.custoBeneficio > melhorCelular->custoBeneficio || 
                (celular.custoBeneficio == melhorCelular->custoBeneficio && celular.preco < melhorCelular->preco)) {
                melhorCelular = &celular;
            }
        }
    }

    if (melhorCelular) {
        cout << "Comprarei o celular " << melhorCelular->nome << endl;
    } else {
        cout << "O meu celular nem esta tao ruim assim" << endl;
    }

    return 0;
}

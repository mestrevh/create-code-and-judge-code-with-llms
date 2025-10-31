/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contato {
    string nome;
    string numero;
    int vinculo;
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<Contato> contatos(n);
    
    for (int i = 0; i < n; ++i) {
        getline(cin, contatos[i].nome);
        getline(cin, contatos[i].numero);
        cin >> contatos[i].vinculo;
        cin.ignore();
    }
    
    string pesquisa;
    
    while (true) {
        getline(cin, pesquisa);
        if (pesquisa == "#") break;
        
        bool encontrado = false;
        
        for (const auto& contato : contatos) {
            if (contato.nome.substr(0, pesquisa.size()) == pesquisa) {
                encontrado = true;
                cout << "Nome: " << contato.nome << endl;
                cout << "Numero: " << contato.numero << endl;
                cout << "Vinculo: " << (contato.vinculo == 1 ? "Familia" : contato.vinculo == 2 ? "Faculdade" : "Amigo") << endl << endl;
            }
        }
        
        if (!encontrado) {
            cout << pesquisa << " nao foi cadastrado" << endl;
        }
    }
    
    return 0;
}

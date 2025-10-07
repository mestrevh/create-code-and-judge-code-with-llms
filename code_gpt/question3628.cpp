/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cliente {
    string nome;
    int senha;
    char situacao;
};

int main() {
    vector<Cliente> clientes;
    string nome;
    
    while (clientes.size() < 100) {
        getline(cin, nome);
        if (nome == "SAIR") break;

        Cliente c;
        c.nome = nome;
        cin >> c.senha >> c.situacao;
        cin.ignore(); // Limpar o buffer
        clientes.push_back(c);
    }
    
    int senha;
    while (true) {
        cin >> senha;
        if (senha == -1) break;

        bool encontrado = false;
        for (const auto& c : clientes) {
            if (c.senha == senha) {
                encontrado = true;
                if (c.situacao == 'P') {
                    cout << c.nome << ", seja bem-vindo(a)!" << endl;
                } else {
                    cout << "Não está esquecendo de algo, " << c.nome << "? Procure a recepção!" << endl;
                }
                break;
            }
        }
        if (!encontrado) {
            cout << "Seja bem-vindo(a)! Procure a recepção!" << endl;
        }
    }
    
    return 0;
}

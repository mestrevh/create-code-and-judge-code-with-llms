/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
using namespace std;

struct Item {
    string nome;
    double valor;
    int quantidade;
};

class ListaDeCompras {
private:
    unordered_map<string, Item> itens;

public:
    void inserir(const string& nome, double valor, int quantidade) {
        if (itens.find(nome) == itens.end()) {
            itens[nome] = {nome, valor, quantidade};
        } else {
            itens[nome].quantidade += quantidade;
        }
    }

    void remover(const string& nome, int quantidade) {
        if (itens.find(nome) != itens.end()) {
            itens[nome].quantidade -= quantidade;
            if (itens[nome].quantidade <= 0) {
                itens.erase(nome);
            }
        }
    }

    void removerGrupo(double valor) {
        for (auto it = itens.begin(); it != itens.end();) {
            if (it->second.valor > valor) {
                it = itens.erase(it);
            } else {
                ++it;
            }
        }
    }

    double consultar() {
        double total = 0;
        for (const auto& item : itens) {
            total += item.second.valor * item.second.quantidade;
        }
        return total;
    }

    void procurar(const string& nome) {
        if (itens.find(nome) != itens.end()) {
            cout << "Nome: " << itens[nome].nome << "\n- Valor: " << itens[nome].valor << "\n- Quantidade: " << itens[nome].quantidade << "\n";
        } else {
            cout << nome << " nao foi encontrado.\n";
        }
    }
};

int main() {
    ListaDeCompras lista;
    string comando;
    while (getline(cin, comando)) {
        if (comando.substr(0, 7) == "INSERIR") {
            string nome;
            double valor;
            int quantidade;
            sscanf(comando.c_str(), "INSERIR %s %lf %d", &nome[0], &valor, &quantidade);
            lista.inserir(nome, valor, quantidade);
        } else if (comando.substr(0, 7) == "REMOVER") {
            string nome;
            int quantidade;
            sscanf(comando.c_str(), "REMOVER %s %d", &nome[0], &quantidade);
            lista.remover(nome, quantidade);
        } else if (comando.substr(0, 12) == "REMOVERGRUPO") {
            double valor;
            sscanf(comando.c_str(), "REMOVERGRUPO %lf", &valor);
            lista.removerGrupo(valor);
        } else if (comando == "CONSULTAR") {
            cout << "Atualmente a lista esta em R$" << fixed << setprecision(1) << lista.consultar() << "\n";
        } else if (comando.substr(0, 8) == "PROCURAR") {
            string nome;
            sscanf(comando.c_str(), "PROCURAR %s", &nome[0]);
            lista.procurar(nome);
        }
    }
    return 0;
}

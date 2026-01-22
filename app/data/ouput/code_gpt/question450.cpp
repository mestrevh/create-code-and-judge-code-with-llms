/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string tipo, descricao;
    map<string, double> ternos = {
        {"simples", 120.40},
        {"completo", 150.35},
        {"fraque", 180.70}
    };
    map<string, double> acessorios = {
        {"gravata", 30.00},
        {"sapato", 80.00},
        {"cinto", 15.00}
    };

    getline(cin, tipo);
    getline(cin, descricao);
    
    transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
    transform(descricao.begin(), descricao.end(), descricao.begin(), ::tolower);

    if (ternos.find(descricao) != ternos.end()) {
        double preco = ternos[descricao] * 0.93;
        cout << fixed << setprecision(2) << preco << endl;
    } else if (acessorios.find(descricao) != acessorios.end()) {
        cout << fixed << setprecision(2) << acessorios[descricao] << endl;
    } else {
        cout << "Item não encontrado" << endl;
    }

    return 0;
}

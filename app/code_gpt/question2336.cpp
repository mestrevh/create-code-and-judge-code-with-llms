/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

class Garagem {
public:
    set<int> modelos;
    void adicionar(int modelo) {
        modelos.insert(modelo);
    }
    
    void imprimir() {
        if (modelos.empty()) {
            cout << "A GARAGEM ESTA VAZIA :(" << endl;
        } else {
            for (auto modelo : modelos) {
                cout << modelo << " ";
            }
            cout << endl;
        }
    }
    
    bool verificar(int modelo) {
        return modelos.count(modelo) > 0;
    }
    
    void vender() {
        map<int, int> contador;
        for (auto modelo : modelos) {
            contador[modelo]++;
        }
        bool repetido = false;
        for (auto &par : contador) {
            if (par.second > 1) {
                repetido = true;
                cout << par.first << " ";
            }
        }
        if (!repetido) {
            cout << "NADA REPETIDO POR ENQUANTO :)" << endl;
        } else {
            cout << endl;
            for (auto &par : contador) {
                if (par.second > 1) {
                    modelos.erase(par.first);
                }
            }
        }
    }
};

map<string, Garagem> garagens;

int main() {
    string comando;
    while (getline(cin, comando)) {
        istringstream iss(comando);
        string operacao;
        int modelo;
        iss >> operacao >> modelo;

        string tipo = to_string(modelo).substr(0, 2);
        if (operacao == "VEICULO!!!") {
            if (tipo == "67" || tipo == "65" || tipo == "77" || tipo == "66" || tipo == "84" || tipo == "83") {
                garagens[tipo].adicionar(modelo);
            } else {
                cout << "VERIFICAR TIPO DE VEICULO" << endl;
            }
        } else if (operacao == "VERIFICAR") {
            if (garagens[tipo].verificar(modelo)) {
                cout << "EXISTE" << endl;
            } else {
                cout << "AINDA NAO" << endl;
            }
        } else if (operacao == "IMPRIMIR") {
            garagens[tipo].imprimir();
        } else if (operacao == "VENDER") {
            garagens[tipo].vender();
        }
    }
    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;

struct Aventura {
    string nome;
    int regeneracao;
    string local;
    int ano;
    set<string> amigos;
    set<string> inimigos;
};

int main() {
    map<string, Aventura> aventuras;
    string linha;
    while (getline(cin, linha) && linha != "----------") {
        Aventura a;
        a.nome = linha;
        getline(cin, linha);
        a.regeneracao = stoi(linha);
        getline(cin, linha);
        a.local = linha;
        getline(cin, linha);
        a.ano = stoi(linha);

        while (getline(cin, linha) && linha != "INIMIGOS") {
            if (linha != "AMIGOS") a.amigos.insert(linha);
        }
        
        while (getline(cin, linha) && linha != "FIM") {
            a.inimigos.insert(linha);
        }

        aventuras[a.nome] = a;
    }

    while (getline(cin, linha)) {
        string tag = linha;
        getline(cin, linha);
        string filtro = linha;
        getline(cin, linha);
        string valor = linha;

        set<string> resultado;
        if (tag == "Aventura") {
            for (const auto &p : aventuras) {
                const Aventura &aventura = p.second;
                if (filtro == "TODOS" || (filtro == "Doctor" && aventura.regeneracao == stoi(valor)) ||
                    (filtro == "Local" && aventura.local == valor) || (filtro == "Ano" && aventura.ano == stoi(valor))) {
                    resultado.insert(aventura.nome);
                }
            }
        } else if (tag == "Amigo" || tag == "Inimigo") {
            for (const auto &p : aventuras) {
                const Aventura &aventura = p.second;
                if (filtro == "TODOS" || (filtro == "Doctor" && aventura.regeneracao == stoi(valor)) ||
                    (filtro == "Local" && aventura.local == valor) || (filtro == "Ano" && aventura.ano == stoi(valor))) {
                    if (tag == "Amigo") {
                        for (const auto &amigo : aventura.amigos) resultado.insert(amigo);
                    } else {
                        for (const auto &inimigo : aventura.inimigos) resultado.insert(inimigo);
                    }
                }
            }
        }

        if (resultado.empty()) {
            cout << "Nao foi possivel encontrar nada com esses parametros." << endl;
        } else {
            for (const auto &r : resultado) cout << r << endl;
        }
        cout << endl;
    }
    return 0;
}

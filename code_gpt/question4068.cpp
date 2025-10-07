/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Peca {
    string tipo;
    int valor;
    int performance;
};

int main() {
    int dinheiro, n;
    cin >> dinheiro >> n;
    vector<Peca> pecas(n);
    for (int i = 0; i < n; i++) {
        cin >> pecas[i].tipo >> pecas[i].valor >> pecas[i].performance;
    }

    int melhorMotor = -1, melhorRoda = -1, melhorLataria = -1;

    for (const auto& p : pecas) {
        if (p.tipo == "Motor") {
            if (melhorMotor == -1 || (p.performance > pecas[melhorMotor].performance) || 
               (p.performance == pecas[melhorMotor].performance && p.valor < pecas[melhorMotor].valor)) {
                melhorMotor = &p - &pecas[0];
            }
        } else if (p.tipo == "Roda") {
            if (melhorRoda == -1 || (p.performance > pecas[melhorRoda].performance) || 
               (p.performance == pecas[melhorRoda].performance && p.valor < pecas[melhorRoda].valor)) {
                melhorRoda = &p - &pecas[0];
            }
        } else if (p.tipo == "Lataria") {
            if (melhorLataria == -1 || (p.performance > pecas[melhorLataria].performance) || 
               (p.performance == pecas[melhorLataria].performance && p.valor < pecas[melhorLataria].valor)) {
                melhorLataria = &p - &pecas[0];
            }
        }
    }

    if (melhorMotor == -1 || melhorRoda == -1 || melhorLataria == -1) {
        cout << "Nao foi possivel construir uma caranga..." << endl;
        return 0;
    }

    int totalValor = pecas[melhorMotor].valor + pecas[melhorRoda].valor + pecas[melhorLataria].valor;

    if (totalValor > dinheiro) {
        cout << "Nao foi possivel construir uma caranga..." << endl;
    } else {
        int performanceTotal = pecas[melhorMotor].performance + pecas[melhorRoda].performance + pecas[melhorLataria].performance;
        int dinheiroRestante = dinheiro - totalValor;
        cout << "Minha nave tem uma performance de " << performanceTotal << " pontos" << endl;
        if (dinheiroRestante > 0)
            cout << "E ainda me sobraram " << dinheiroRestante << " mangos!" << endl;
    }

    return 0;
}

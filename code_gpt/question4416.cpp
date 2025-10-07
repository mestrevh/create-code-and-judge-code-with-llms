/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Carro {
    string nome;
    double tempo;
    double velocidade;
};

int main() {
    int limiteVelocidade;
    double distancia;
    cin >> limiteVelocidade >> distancia;

    vector<Carro> carros = {
        {"Kwid Laranja", 100},
        {"Tesla Branco", 50.25},
        {"Gol Bolinha", 5}
    };

    double minVelocidade = limiteVelocidade / 2.0;
    vector<Carro> carrosValidos;

    for (auto& carro : carros) {
        carro.velocidade = distancia / carro.tempo * 3600; // km/h
        if (carro.velocidade <= limiteVelocidade && carro.velocidade >= minVelocidade) {
            carrosValidos.push_back(carro);
        }
    }

    sort(carrosValidos.begin(), carrosValidos.end(), [](const Carro &a, const Carro &b) {
        return a.velocidade > b.velocidade;
    });

    if (carrosValidos.empty()) {
        cout << "Infelizmente Xupenio nao podera ir ao evento mais importante do ano" << endl;
    } else {
        cout << fixed << setprecision(2);
        for (const auto& carro : carrosValidos) {
            cout << "Xupenio pode utilizar o carro " << carro.nome 
                 << ", cuja velocidade no percurso eh " << carro.velocidade << endl;
        }
    }

    return 0;
}

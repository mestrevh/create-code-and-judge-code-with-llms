/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Carro {
    string modelo;
    float motor;
    float suspensao;
    float turbo;
    float desempenho;
};

float calcularDesempenho(float motor, float suspensao, float turbo) {
    return (motor * 5 + suspensao * 2 + turbo * 3) / 10;
}

int main() {
    int n;
    cin >> n;
    vector<Carro> carros(n);
    float somaDesempenho = 0;

    for (int i = 0; i < n; ++i) {
        cin.ignore();
        getline(cin, carros[i].modelo);
        cin >> carros[i].motor >> carros[i].suspensao >> carros[i].turbo;
        carros[i].desempenho = calcularDesempenho(carros[i].motor, carros[i].suspensao, carros[i].turbo);
        somaDesempenho += carros[i].desempenho;
    }

    float mediaDesempenho = somaDesempenho / n;

    for (const auto& carro : carros) {
        if (carro.desempenho >= mediaDesempenho) {
            cout << carro.modelo << endl;
        }
    }

    return 0;
}

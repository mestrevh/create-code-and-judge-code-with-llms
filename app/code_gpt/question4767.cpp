/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double horarioAtual, tempoEstimado;
    int vagasDisponiveis;

    cin >> horarioAtual >> tempoEstimado >> vagasDisponiveis;

    if (horarioAtual < 8.0 || horarioAtual > 20.0) {
        cout << "ulaM esta dormindo" << endl;
        return 0;
    }

    double horarioChegada = horarioAtual + tempoEstimado / 60.0;
    if (horarioChegada < 8.0 || horarioChegada > 20.0) {
        cout << "ulaM esta dormindo" << endl;
        return 0;
    }

    int vagasPerdidas = 0;

    if (horarioAtual < 12.0) {
        vagasPerdidas = static_cast<int>((tempoEstimado / 5.0) / 1.0);
    } else if (horarioAtual < 16.0) {
        vagasPerdidas = static_cast<int>((tempoEstimado / 4.0) / 1.0);
    } else {
        vagasPerdidas = static_cast<int>((tempoEstimado / 2.0) / 1.0);
    }

    int vagasRestantes = vagasDisponiveis - vagasPerdidas;

    if (vagasRestantes >= 1) {
        cout << "possui vaga para olecraM" << endl;
    } else {
        cout << "nao tera vaga" << endl;
    }

    return 0;
}

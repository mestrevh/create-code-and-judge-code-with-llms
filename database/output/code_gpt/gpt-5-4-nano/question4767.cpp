/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double horaAtual;
    double tempoTrajeto;
    int vagas;
    if (!(cin >> horaAtual >> tempoTrajeto >> vagas)) return 0;

    double horaSaida = horaAtual;
    double horaChegada = horaSaida + tempoTrajeto / 60.0;

    auto outside = [&](double h) {
        return h < 8.0 - 1e-9 || h > 20.0 + 1e-9;
    };

    if (outside(horaSaida) || outside(horaChegada)) {
        cout << "ulaM esta dormindo";
        return 0;
    }

    double t = horaSaida;
    double end = horaChegada;

    const double b1 = 12.0, b2 = 16.0;

    auto rateToMinutes = [&](double h) -> double {
        if (h >= 8.0 && h < b1) return 5.0;
        if (h >= b1 && h < b2) return 4.0;
        return 2.0;
    };

    int totalDecrementos = 0;

    while (t < end - 1e-12) {
        double nextBoundary = end;
        if (t < b1) nextBoundary = min(nextBoundary, b1);
        else if (t < b2) nextBoundary = min(nextBoundary, b2);
        else nextBoundary = end;

        double segmentHours = nextBoundary - t;
        double segmentMinutes = segmentHours * 60.0;

        double gap = rateToMinutes(t);
        int dec = (int) floor(segmentMinutes / gap + 1e-12);
        totalDecrementos += dec;

        t = nextBoundary;
        if (nextBoundary >= end - 1e-12) break;
        if (gap == 0) break;
    }

    int restantes = vagas - totalDecrementos;
    if (restantes >= 1) cout << "possui vaga para olecraM";
    else cout << "nao tera vaga";

    return 0;
}
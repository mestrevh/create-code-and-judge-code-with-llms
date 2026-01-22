/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Jogador {
    string nome;
    double indice;
};

double calcularIndice(int desempenho, int gols, int cansaço, int entrosamento) {
    if ((desempenho == 0 && cansaço == 0) || (gols < 0)) return 0;
    return desempenho * 2 + gols * 3.5 + cansaço * 1.5 + entrosamento * 2;
}

int main() {
    vector<Jogador> jogadores;
    for (int i = 0; i < 5; ++i) {
        Jogador j;
        int desempenho, gols, cansaço, entrosamento;
        cin >> j.nome >> desempenho >> gols >> cansaço >> entrosamento;
        j.indice = calcularIndice(desempenho, gols, cansaço, entrosamento);
        if (j.indice > 0) jogadores.push_back(j);
    }
    sort(jogadores.begin(), jogadores.end(), [](Jogador a, Jogador b) {
        return a.indice > b.indice;
    });
    for (int i = 0; i < min(3, (int)jogadores.size()); ++i) {
        cout << jogadores[i].indice << endl;
    }
    return 0;
}

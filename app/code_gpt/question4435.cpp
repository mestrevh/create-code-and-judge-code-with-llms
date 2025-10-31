/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

struct Brinquedo {
    string nome;
    int d;
    int a;
    int vezes;
};

int calcularDiversao(const Brinquedo& b, int t) {
    return b.d - (t * t) * b.a;
}

int main() {
    vector<Brinquedo> brinquedos(3);
    for (int i = 0; i < 3; i++) {
        cin >> ws;
        getline(cin, brinquedos[i].nome);
        cin >> brinquedos[i].d >> brinquedos[i].a;
        brinquedos[i].vezes = 0;
    }

    vector<tuple<int, int, int>> divs; // (diversão, índice do brinquedo, vezes)
    for (int i = 0; i < 3; i++) {
        divs.emplace_back(calcularDiversao(brinquedos[i], 0), i, 0);
        divs.emplace_back(calcularDiversao(brinquedos[i], 1), i, 1);
        divs.emplace_back(calcularDiversao(brinquedos[i], 2), i, 2);
    }
    
    sort(divs.rbegin(), divs.rend());
    
    int totalDiversao = 0;
    for (int i = 0; i < 3; i++) {
        int idx = get<1>(divs[i]);
        int vezes = get<2>(divs[i]);
        brinquedos[idx].vezes++;
        totalDiversao += calcularDiversao(brinquedos[idx], vezes);
    }

    map<string, int> ordem;
    for (const auto& b : brinquedos) {
        if (b.vezes > 0) {
            ordem[b.nome] += b.vezes;
        }
    }

    cout << "a maior diversao foi: " << totalDiversao << endl;
    cout << "indo nos brinquedos:";
    for (const auto& [nome, vezes] : ordem) {
        cout << " " << nome << " " << vezes << " vez" << (vezes > 1 ? "es" : "") << ",";
    }
    cout << "\b. " << endl;

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;

struct Estabelecimento {
    string nome;
    int x, y;
    string sabor;
    double preco;
};

double calcularDistancia(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int inicioX, inicioY;
    cin >> inicioX >> inicioY;
    
    int n;
    cin >> n;
    vector<Estabelecimento> estabelecimentos(n);
    
    for (int i = 0; i < n; i++) {
        cin >> estabelecimentos[i].nome >> estabelecimentos[i].x >> estabelecimentos[i].y >> estabelecimentos[i].sabor >> estabelecimentos[i].preco;
    }

    int k;
    cin >> k;
    set<string> listaDesejos;
    
    for (int i = 0; i < k; i++) {
        string sabor;
        cin >> sabor;
        listaDesejos.insert(sabor);
    }
    
    vector<string> visitados;
    set<string> saboresProvados;

    pair<int, int> posicaoAtual = {inicioX, inicioY};

    while (!estabelecimentos.empty()) {
        auto it = min_element(estabelecimentos.begin(), estabelecimentos.end(), [&](const Estabelecimento &a, const Estabelecimento &b) {
            double distA = calcularDistancia(posicaoAtual.first, posicaoAtual.second, a.x, a.y);
            double distB = calcularDistancia(posicaoAtual.first, posicaoAtual.second, b.x, b.y);
            if (distA == distB) {
                return a.preco < b.preco;
            }
            return distA < distB;
        });

        postionAtual = {it->x, it->y};
        visitados.push_back(it->nome);
        saboresProvados.insert(it->sabor);
        
        estabelecimentos.erase(it);
    }
    
    for (const string& nome : visitados) {
        cout << nome << endl;
    }
    
    if (saboresProvados == listaDesejos) {
        cout << "Completou a lista" << endl;
    } else {
        cout << "Vou fazer as que faltaram quando chegar em casa" << endl;
    }
    
    return 0;
}

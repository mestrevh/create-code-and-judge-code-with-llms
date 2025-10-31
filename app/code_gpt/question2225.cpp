/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int moedas;
    cin >> moedas;
    
    vector<pair<string, pair<int, int>>> yoshis = {
        {"Verde", {80, 0}}, 
        {"Vermelho", {100, 1}}, 
        {"Roxo", {120, 2}}, 
        {"Amarelo", {80, 3}}
    };
    
    vector<int> precos(4);
    for (int i = 0; i < 4; ++i) {
        cin >> precos[i];
    }

    double melhor_custo_beneficio = -1;
    string melhor_yoshi = "Acho que vou a pé :(";

    for (auto& yoshi : yoshis) {
        int velocidade = yoshi.second.first;
        int indice = yoshi.second.second;
        
        if (precos[indice] <= moedas) {
            double custo_beneficio = static_cast<double>(velocidade) / precos[indice];

            if (custo_beneficio > melhor_custo_beneficio || 
                (custo_beneficio == melhor_custo_beneficio && melhor_yoshi == "Acho que vou a pé :(")) {
                melhor_custo_beneficio = custo_beneficio;
                melhor_yoshi = yoshi.first;
            }
        }
    }

    cout << melhor_yoshi << endl;
    return 0;
}

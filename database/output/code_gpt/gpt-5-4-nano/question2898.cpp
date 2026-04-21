/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N_fome, N_pratos;
    if (!(cin >> N_fome >> N_pratos)) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    unordered_map<string, long long> kcal = {
        {"Arroz", 25},
        {"Churrasco de Animal do Mar", 100},
        {"Paella Vestido de Camarao", 70},
        {"Massa de Tinta de Lula Rosa", 55},
        {"Mizu Mizu Doces", 15}
    };

    long long total = 0;
    for (int i = 0; i < (int)N_pratos; i++) {
        string line;
        getline(cin, line);
        while(line.size() && line.back()=='\r') line.pop_back();
        if(kcal.count(line)) total += kcal[line];
    }

    long long remaining = N_fome - total;
    if (remaining > 0) {
        cout << "Pell, voe e traga mais comida ou a festa sera arruinada!";
    } else {
        cout << "Sucesso, vamos todos celebrar.";
    }
    return 0;
}
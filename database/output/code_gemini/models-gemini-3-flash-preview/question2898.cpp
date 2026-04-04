/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long hunger;
    int n_pratos;

    if (!(cin >> hunger >> n_pratos)) return 0;

    string line;
    getline(cin, line); // Consome o restante da primeira linha

    for (int i = 0; i < n_pratos; ++i) {
        if (!getline(cin, line)) break;
        if (line.empty()) {
            i--;
            continue;
        }

        if (line == "Arroz") {
            hunger -= 25;
        } else if (line == "Churrasco de Animal do Mar") {
            hunger -= 100;
        } else if (line == "Paella Vestido de Camarao") {
            hunger -= 70;
        } else if (line == "Massa de Tinta de Lula Rosa") {
            hunger -= 55;
        } else if (line == "Mizu Mizu Doces") {
            hunger -= 15;
        }
    }

    if (hunger > 0) {
        cout << "Pell, voe e traga mais comida ou a festa sera arruinada!" << endl;
    } else {
        cout << "Sucesso, vamos todos celebrar." << endl;
    }

    return 0;
}
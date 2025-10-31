/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n_fome, n_pratos;
    cin >> n_fome >> n_pratos;
    cin.ignore();

    unordered_map<string, int> menu = {
        {"Arroz", 25},
        {"Churrasco de Animal do Mar", 100},
        {"Paella Vestido de Camarao", 70},
        {"Massa de Tinta de Lula Rosa", 55},
        {"Mizu Mizu Doces", 15}
    };

    string prato;
    for (int i = 0; i < n_pratos; i++) {
        getline(cin, prato);
        n_fome -= menu[prato];
    }

    if (n_fome > 0) {
        cout << "Pell, voe e traga mais comida ou a festa sera arruinada!" << endl;
    } else {
        cout << "Sucesso, vamos todos celebrar." << endl;
    }

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, string> vantagem;
    vantagem["Fogo"] = "Planta";
    vantagem["Planta"] = "Agua";
    vantagem["Agua"] = "Fogo";

    string ataque, defesa;
    cin >> ataque >> defesa;

    if (ataque == defesa) {
        cout << "Empate" << endl;
    } else if (vantagem[ataque] == defesa) {
        cout << "Vantagem" << endl;
    } else {
        cout << "Desvantagem" << endl;
    }

    return 0;
}

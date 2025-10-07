/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, string> advantage;
    advantage["Fogo"] = "Planta";
    advantage["Planta"] = "Agua";
    advantage["Agua"] = "Fogo";

    string ataque, defesa;
    cin >> ataque >> defesa;

    if (ataque == defesa) {
        cout << "Empate";
    } else if (advantage[ataque] == defesa) {
        cout << "Vantagem";
    } else {
        cout << "Desvantagem";
    }

    return 0;
}

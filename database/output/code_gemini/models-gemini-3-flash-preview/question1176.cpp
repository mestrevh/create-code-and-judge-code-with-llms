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

    string ataque, defesa;
    if (!(cin >> ataque >> defesa)) return 0;

    if (ataque == defesa) {
        cout << "Empate" << endl;
    } else if ((ataque == "Agua" && defesa == "Fogo") || 
               (ataque == "Fogo" && defesa == "Planta") || 
               (ataque == "Planta" && defesa == "Agua")) {
        cout << "Vantagem" << endl;
    } else {
        cout << "Desvantagem" << endl;
    }

    return 0;
}
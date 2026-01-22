/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string choices[5];
    int miguelWins = 0, mariaWins = 0;

    for (int i = 0; i < 5; ++i) {
        string miguel, maria;
        cin >> miguel >> maria;
        transform(miguel.begin(), miguel.end(), miguel.begin(), ::tolower);
        transform(maria.begin(), maria.end(), maria.begin(), ::tolower);

        if (miguel == maria) continue;
        if ((miguel == "pedra" && maria == "tesoura") || 
            (miguel == "papel" && maria == "pedra") || 
            (miguel == "tesoura" && maria == "papel")) {
            miguelWins++;
        } else {
            mariaWins++;
        }
    }

    cout << (miguelWins > mariaWins ? "MIGUEL" : "MARIA") << endl;
    return 0;
}

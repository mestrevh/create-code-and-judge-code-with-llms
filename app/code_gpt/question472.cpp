/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int idade, totalFraldas = 0;
    string resposta;

    while (true) {
        cin >> idade;
        cin >> resposta;

        if (resposta == "nao" || resposta == "não" || resposta == "NAO" || resposta == "NÃO" || resposta == "Nao" || resposta == "Não") {
            break;
        }

        if (idade <= 2) {
            totalFraldas += 9 * 30;
        } else {
            totalFraldas += 6 * 30;
        }
    }

    int pacotes = totalFraldas / 100;
    int sobras = totalFraldas % 100;

    cout << pacotes << endl;
    cout << sobras << endl;

    return 0;
}

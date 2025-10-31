/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    string pacote, pagamento;
    getline(cin, pacote);
    getline(cin, pagamento);

    transform(pacote.begin(), pacote.end(), pacote.begin(), ::tolower);
    transform(pagamento.begin(), pagamento.end(), pagamento.begin(), ::tolower);

    double preco;
    int canais;

    if (pacote == "básico") {
        preco = 80.80;
        canais = 32 + 6;
    } else if (pacote == "entretenimento") {
        preco = 100.40;
        canais = 55 + 6;
    } else if (pacote == "multicultural") {
        preco = 130.23;
        canais = 70 + 11;
    } else if (pacote == "completo") {
        preco = 215.50;
        canais = 112 + 11;
    } else {
        return 0;
    }

    if (pagamento == "débito automático") {
        if (pacote == "básico" || pacote == "entretenimento") {
            preco *= 0.95;
        } else {
            preco *= 0.90;
        }
    }

    cout << fixed << setprecision(2) << preco << endl;
    cout << canais << endl;
    
    return 0;
}

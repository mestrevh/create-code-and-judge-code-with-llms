/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string rg, rgDate, passagem, passagemDate, assento;
        cin >> rg >> rgDate >> passagem >> passagemDate >> assento;

        if (rg == "Nao possui") {
            cout << "a saida e nessa direção" << endl;
        } 
        else if (passagem == "Nao possui") {
            cout << "a recepção e nessa direção" << endl;
        } 
        else if (rgDate != passagemDate) {
            cout << "190" << endl;
        } 
        else {
            cout << "o seu assento e " << assento << " tenha um bom dia" << endl;
        }
    }
    return 0;
}

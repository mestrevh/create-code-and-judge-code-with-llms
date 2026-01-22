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
    string gabarito, respostas;
    cin >> gabarito >> respostas;

    int acertos = 0;
    for (int i = 0; i < N; i++) {
        if (gabarito[i] == respostas[i]) {
            acertos++;
        }
    }

    cout << acertos << endl;
    return 0;
}

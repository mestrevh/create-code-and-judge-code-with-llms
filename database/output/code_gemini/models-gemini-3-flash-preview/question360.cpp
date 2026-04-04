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

    int N;
    if (!(cin >> N)) return 0;

    string gabarito, respostas;
    if (!(cin >> gabarito >> respostas)) return 0;

    int acertos = 0;
    for (int i = 0; i < N; ++i) {
        if (gabarito[i] == respostas[i]) {
            acertos++;
        }
    }

    cout << acertos << "\n";

    return 0;
}
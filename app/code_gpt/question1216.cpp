/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    int current = 0;
    bool exceeded = false;

    for (int i = 0; i < N; i++) {
        int S, E;
        cin >> S >> E;
        current -= S;
        current += E;
        if (current > C) {
            exceeded = true;
        }
    }

    if (exceeded) {
        cout << "Selvagens sao dificeis de ensinar." << endl;
    } else {
        cout << "Viva a conscientizacao." << endl;
    }

    return 0;
}

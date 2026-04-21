/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    if (!(cin >> t)) return 0;

    if (t < 0) {
        cout << "Meme man quebrou o tempo! De volta ao transito :(" << "\n";
    } else if (t < 62) {
        cout << "...Ainda no transito..." << "\n";
    } else {
        if (t == 62) {
            cout << "Stonks has been born!" << "\n";
        } else {
            cout << "Lar doce lar" << "\n";
        }
    }
    return 0;
}
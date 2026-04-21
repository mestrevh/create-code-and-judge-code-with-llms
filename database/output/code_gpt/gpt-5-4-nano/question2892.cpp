/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cout << "Digite a ordem N da matriz:\n";
    if (!(cin >> N)) return 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            if (i == j) val = 1;
            else if (j > i) val = 10;
            else val = -10;

            cout << setw(7) << left << val;
        }
        if (i + 1 < N) cout << "\n";
    }
    return 0;
}
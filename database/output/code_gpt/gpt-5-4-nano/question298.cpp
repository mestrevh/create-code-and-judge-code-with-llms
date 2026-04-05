/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long E, K;
    int N;
    if (!(cin >> E)) return 0;
    cin >> K >> N;

    long long estoque = E;

    for (int i = 1; i <= N; i++) {
        long long SE, SA, DO;
        cin >> SE >> SA >> DO;
        estoque -= 4 * K;
        if (estoque < 0) {
            cout << i << " " << estoque << "\n";
            return 0;
        }
        estoque -= (SE + SA + DO);
        if (estoque < 0) {
            cout << i << " " << estoque << "\n";
            return 0;
        }
    }

    cout << estoque << "\n";
    return 0;
}
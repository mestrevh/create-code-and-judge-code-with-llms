/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    if (!getline(cin, S)) return 0;

    int N;
    if (!(cin >> N)) return 0;

    int m = (int)S.size();
    for (int k = 0; k < N; k++) {
        int I;
        char C;
        cin >> I;
        cin >> C;
        if (I >= 0 && I < m) S[I] = C;
    }

    cout << "SC - " << S;
    return 0;
}
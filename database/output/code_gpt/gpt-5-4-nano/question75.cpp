/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int,long long> cap;
    for (int i = 0; i < 37; i++) {
        long long v, c;
        if (!(cin >> v >> c)) return 0;
        cap[(int)v] = c;
    }

    while (true) {
        int doc;
        int flight;
        if (!(cin >> doc)) break;
        if (!(cin >> flight)) break;
        if (doc == 9999) break;

        auto it = cap.find(flight);
        if (it == cap.end() || it->second <= 0) {
            cout << "INDISPONIVEL\n";
        } else {
            it->second--;
            cout << doc << "\n";
        }
    }
    return 0;
}
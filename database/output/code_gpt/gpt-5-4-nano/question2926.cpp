/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    while (cin >> X) {
        if (X < 3 || X > 20) return 0;

        unordered_map<string, array<string,3>> prefs;
        prefs.reserve(X * 2);

        for (int i = 0; i < X; i++) {
            string name;
            string p1, p2, p3;
            cin >> name >> p1 >> p2 >> p3;
            prefs[name] = {p1, p2, p3};
        }

        string name, present;
        while (cin >> name) {
            if (name == "FIM") break;
            cin >> present;

            auto it = prefs.find(name);
            bool ok = false;
            if (it != prefs.end()) {
                auto &arr = it->second;
                ok = (present == arr[0] || present == arr[1] || present == arr[2]);
            }

            if (ok) cout << "Uhul! Seu amigo secreto vai adorar\n";
            else cout << "Tente Novamente!\n";
        }
    }
    return 0;
}
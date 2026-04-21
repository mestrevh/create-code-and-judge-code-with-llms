/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string upperStr(string s) {
    for (char &c : s) c = toupper((unsigned char)c);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string name, cont;
    double h;

    bool hasAny = false;
    string minName, maxName;
    double minH = 0.0, maxH = 0.0;

    while (cin >> name) {
        if (!(cin >> h)) break;

        if (!hasAny) {
            minH = maxH = h;
            minName = maxName = name;
            hasAny = true;
        } else {
            if (h < minH) {
                minH = h;
                minName = name;
            }
            if (h > maxH) {
                maxH = h;
                maxName = name;
            }
        }

        if (!(cin >> cont)) break;

        string contUpper = upperStr(cont);
        if (contUpper == "FIM") break;
    }

    cout << upperStr(minName) << "\n" << upperStr(maxName);
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string name;
    double h;
    bool first = true;
    string bestName;
    double bestH = 0.0;

    while (cin >> name) {
        if (name == "parar") break;
        if (!(cin >> h)) break;
        if (first || h > bestH) {
            first = false;
            bestH = h;
            bestName = name;
        }
    }

    long long cm = llround(bestH * 100.0 + 1e-9);
    cout << "O aluno mais alto tem " << cm << " cm e se chama " << bestName << ".";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string normalize(const string& s) {
    string t;
    t.reserve(s.size());
    for (unsigned char c : s) {
        if (isspace(c)) continue;
        t.push_back(tolower(c));
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string comida, bebida;
    if (!getline(cin, comida)) return 0;
    if (!getline(cin, bebida)) return 0;

    string c = normalize(comida);
    string b = normalize(bebida);

    double precoComida = 0.0, precoBebida = 0.0;

    if (c == "lasanha") precoComida = 8.00;
    else if (c == "estrogonofe") precoComida = 11.00;

    if (b == "refrigerante") precoBebida = 3.00;
    else if (b == "suco") precoBebida = 2.50;

    double total = precoComida + precoBebida;

    cout.setf(ios::fixed);
    cout << setprecision(2) << total;
    return 0;
}
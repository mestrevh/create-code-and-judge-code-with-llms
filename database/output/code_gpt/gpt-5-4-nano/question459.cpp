/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int idade;
    string porte;
    if (!(cin >> idade)) return 0;
    if (!(cin >> porte)) return 0;

    string p;
    p.reserve(porte.size());
    for (char c : porte) p.push_back(tolower((unsigned char)c));

    int firstYearHuman = 5;
    int smallIncrement = 3;
    int mediumIncrement = 4;
    int largeIncrement = 5;

    int inc = 0;
    if (p == "pequeno") inc = smallIncrement;
    else if (p == "medio" || p == "médio") inc = mediumIncrement;
    else if (p == "grande") inc = largeIncrement;
    else inc = mediumIncrement;

    int ans;
    if (idade <= 1) ans = firstYearHuman;
    else ans = firstYearHuman + (idade - 1) * inc;

    cout << ans;
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long totalPeople = 0;
    long long x;

    while (true) {
        if (!(cin >> x)) break;
        totalPeople += x;

        string s;
        if (!(cin >> s)) break;

        string lower;
        lower.reserve(s.size());
        for (char c : s) lower.push_back((char)tolower((unsigned char)c));

        if (lower == "sair" || lower.find("sair") != string::npos) break;
        if (cin.fail()) break;
    }

    cout << totalPeople << "\n";
    cout << fixed << setprecision(2) << (double)totalPeople * 14.0 << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    long long add;
    if (!(cin >> s)) return 0;
    cin >> add;

    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    long long total = h * 60 + m;
    total = (total + add) % (24 * 60);
    if (total < 0) total += 24 * 60;

    int nh = (int)(total / 60);
    int nm = (int)(total % 60);

    cout << setw(2) << setfill('0') << nh << ":" << setw(2) << setfill('0') << nm << "\n";
    return 0;
}
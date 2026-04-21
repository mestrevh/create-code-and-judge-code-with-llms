/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a, b;
    long long x;

    cout << "Digite o vetor 1: ";
    while (cin >> x) {
        if (x < 0) break;
        a.push_back(x);
    }

    cout << "\nDigite o vetor 2: ";
    while (cin >> x) {
        if (x < 0) break;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    vector<long long> inter;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(inter));

    cout << "\n\nVetor 1 (ordenado): ";
    for (auto v : a) cout << v << ' ';

    cout << "\nVetor 2 (ordenado): ";
    for (auto v : b) cout << v << ' ';

    cout << "\nVetor interseção (ordenado): ";
    for (auto v : inter) cout << v << ' ';

    return 0;
}
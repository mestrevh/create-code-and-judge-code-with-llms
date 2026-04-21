/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    unordered_set<long long> seen;
    long long x;

    while (cin >> x) {
        if (x == 0) {
            if (a.size() < 3) {
                cout << "você deve digitar pelo menos 3 números antes do 0.\n";
                continue;
            }
            break;
        }
        if (seen.count(x)) {
            cout << "número já existe na lista, tente outro.\n";
            continue;
        }
        a.push_back(x);
        seen.insert(x);
    }

    cout << "[";
    for (size_t i = 0; i < a.size(); i++) {
        if (i) cout << ", ";
        cout << a[i];
    }
    cout << "]\n";

    size_t posMax = 0, posMin = 0;
    for (size_t i = 1; i < a.size(); i++) {
        if (a[i] > a[posMax]) posMax = i;
        if (a[i] < a[posMin]) posMin = i;
    }

    cout << "o maior elemento da lista é: " << a[posMax] << " e ele se encontra na posição: " << posMax << "\n";
    cout << "o menor elemento da lista é: " << a[posMin] << " e ele se encontra na posição: " << posMin << "\n";

    return 0;
}
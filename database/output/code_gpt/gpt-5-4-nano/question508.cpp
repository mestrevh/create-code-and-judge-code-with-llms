/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    vector<long long> a;
    while (a.size() < 5 && (cin >> x)) a.push_back(x);
    while (a.size() < 5) a.push_back(0);

    long long sum = 0;
    for (auto v : a) sum += v;

    long long media = sum / 5;

    long long total = media * 100;

    long long h = total / 3600;
    long long m = (total % 3600) / 60;
    long long s = total % 60;

    cout << media << "\n" << h << "\n" << m << "\n" << s;
    return 0;
}
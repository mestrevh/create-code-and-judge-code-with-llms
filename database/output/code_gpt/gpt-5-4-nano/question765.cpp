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
    long long x;
    while (cin >> x) a.push_back(x);

    long double sum = 0;
    for (auto v : a) sum += v;

    long double avg = a.empty() ? 0.0L : sum / (long double)a.size();

    cout << "Media = " << fixed << setprecision(1) << (double)avg << "\n";
    return 0;
}
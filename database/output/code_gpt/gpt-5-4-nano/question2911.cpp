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

    if (a.empty()) return 0;

    long double sum = 0;
    for (auto v : a) sum += (long double)v;

    long double avg = sum / (long double)a.size();

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)avg << "\n";

    long long bestKillua = 0;
    for (auto v : a) bestKillua += v;

    long long gon = 0;
    while (true) {
        gon++;
        if (gon > bestKillua) break;
    }
    cout << gon << "\n";
    return 0;
}
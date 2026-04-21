/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int X;
    if (!(cin >> X)) return 0;
    long long damageSum = 0;
    long long Y;
    long long lastT = 0;
    vector<pair<long long,long long>> events;
    events.reserve(X);
    for (int i = 0; i < X; i++) {
        long long D, T;
        cin >> D >> T;
        events.push_back({D, T});
        damageSum += D;
        lastT = max(lastT, T);
    }
    cin >> Y;
    
    long long recovered = Y * lastT;
    long long hp = 100 - damageSum + recovered;
    if (hp <= 0) cout << "Inimigo Morto";
    else cout << "Inimigo Vivo";
    return 0;
}
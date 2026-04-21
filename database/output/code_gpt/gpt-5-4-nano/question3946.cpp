/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool parseSimNao(const string& s) {
    return s == "sim";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<tuple<long double, string>> clubs;
    clubs.reserve(n);

    for (int i = 0; i < n; i++) {
        string name;
        long double market;
        int bigPlayers;
        int titles;
        string hasNeymar, isFlamengo2019;

        cin >> ws;
        getline(cin, name);
        while (name.size() == 0 && cin) getline(cin, name);

        cin >> market >> bigPlayers >> titles;
        cin >> hasNeymar >> isFlamengo2019;

        long double score = market + (long double)bigPlayers * 100.0L + (long double)titles * 2000.0L;
        if (parseSimNao(hasNeymar)) score += 10000.0L;
        if (parseSimNao(isFlamengo2019)) score += 20000.0L;

        clubs.emplace_back(score, name);
    }

    sort(clubs.begin(), clubs.end(), [](const auto& a, const auto& b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
        return get<1>(a) < get<1>(b);
    });

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    for (const auto& t : clubs) {
        cout << get<1>(t) << " " << (double)get<0>(t) << "\n";
    }
    return 0;
}
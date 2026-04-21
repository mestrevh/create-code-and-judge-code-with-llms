/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;

    vector<pair<string,int>> dinos;
    while (true) {
        if (!(cin >> N)) break;
        if (!(cin >> S)) break;
        dinos.push_back({S, N});
    }

    sort(dinos.begin(), dinos.end(), [](const auto& a, const auto& b){
        return a.first < b.first;
    });

    vector<string> res;
    for (auto &p : dinos) {
        res.insert(res.end(), p.second, p.first);
    }

    cout << "[";
    for (size_t i = 0; i < res.size(); i++) {
        if (i) cout << ", ";
        cout << res[i];
    }
    cout << "]";
    return 0;
}
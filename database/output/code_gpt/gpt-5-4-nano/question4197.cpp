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
    if (!(cin >> N)) return 0;
    vector<pair<string,string>> res;
    res.reserve(N);

    auto shiftChar = [](char c, int sh) {
        int x = c - 'a';
        x = (x + sh) % 26;
        return char('a' + x);
    };

    for (int i = 0; i < N; i++) {
        string name, cpf;
        cin >> name >> cpf;

        string pass;
        int m = (int)name.size();
        pass.resize(m);
        for (int j = 0; j < m; j++) {
            int sh = cpf[j] - '0';
            pass[j] = shiftChar(name[j], sh);
        }
        pass += cpf.substr(9, 2);
        res.push_back({name, pass});
    }

    sort(res.begin(), res.end(), [](const auto& a, const auto& b){
        return a.first < b.first;
    });

    for (auto &p : res) {
        cout << p.first << ' ' << p.second << "\n";
    }

    return 0;
}
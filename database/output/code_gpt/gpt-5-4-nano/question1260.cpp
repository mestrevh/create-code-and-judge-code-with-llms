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
    vector<pair<long long, string>> v;
    v.reserve(N);

    string line;
    getline(cin, line);
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        size_t pos = line.rfind('#');
        long long id = 0;
        if (pos != string::npos) {
            string num = line.substr(pos + 1);
            id = stoll(num);
        }
        v.push_back({id, line});
    }

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    for (int i = 0; i < N; i++) {
        cout << v[i].second << "\n";
    }
    return 0;
}
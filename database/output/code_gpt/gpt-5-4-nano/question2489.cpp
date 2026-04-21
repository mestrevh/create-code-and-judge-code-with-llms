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
    string line;
    getline(cin, line);

    vector<string> goals;
    goals.reserve(N);
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        goals.push_back(line);
    }

    int M;
    cin >> M;
    getline(cin, line);

    unordered_set<string> done;
    done.reserve(M * 2 + 1);

    for (int i = 0; i < M; i++) {
        getline(cin, line);
        if (find(goals.begin(), goals.end(), line) != goals.end()) done.insert(line);
    }

    vector<string> remaining;
    for (const auto& g : goals) {
        if (!done.count(g)) remaining.push_back(g);
    }

    if (remaining.empty()) {
        cout << "Smelly Cat, Smelly Cat, what are they feeding you?";
    } else {
        cout << "Ainda falta(m) " << remaining.size() << " objetivo(s)!\n";
        for (size_t i = 0; i < remaining.size(); i++) {
            cout << remaining[i];
            if (i + 1 < remaining.size()) cout << "\n";
        }
    }

    return 0;
}
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

    vector<string> names = {"Shun", "Hyoga", "Seiya", "Shiryu", "Ikki"};
    unordered_map<string, int> score;
    for (auto &s : names) score[s] = 0;

    for (int i = 0; i < N; i++) {
        string a, b, w;
        cin >> a >> b >> w;
        if (a == w) score[a] += 3, score[b] -= 1;
        else if (b == w) score[b] += 3, score[a] -= 1;
        else {
            if (score.find(w) == score.end()) continue;
            if (a == w) score[a] += 3, score[b] -= 1;
            else score[b] += 3, score[a] -= 1;
        }
    }

    vector<pair<int,string>> arr;
    arr.reserve(5);
    for (auto &s : names) arr.push_back({score[s], s});

    auto cmp = [](const pair<int,string>& x, const pair<int,string>& y) {
        if (x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    };
    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < 3; i++) {
        cout << arr[i].second << ' ' << arr[i].first << "\n";
    }
    return 0;
}
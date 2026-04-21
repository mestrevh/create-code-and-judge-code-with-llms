/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    long long d, a;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Item> items(3);
    for (int i = 0; i < 3; i++) {
        if (!getline(cin, items[i].name)) return 0;
        while (!items[i].name.empty() && (items[i].name.back() == '\r')) items[i].name.pop_back();
        string line;
        if (!getline(cin, line)) return 0;
        while (line.size() == 0) {
            if (!getline(cin, line)) return 0;
        }
        stringstream ss(line);
        ss >> items[i].d >> items[i].a;
    }

    long long bestScore = LLONG_MIN;
    array<int,3> bestCnt{0,0,0};

    for (int c0 = 0; c0 <= 3; c0++) {
        for (int c1 = 0; c1 <= 3; c1++) {
            int c2 = 3 - c0 - c1;
            if (c2 < 0) continue;

            array<int,3> cnt{c0,c1,c2};
            long long score = 0;
            for (int i = 0; i < 3; i++) {
                for (int t = 0; t < cnt[i]; t++) {
                    long long x = (long long)t;
                    score += items[i].d - x*x*items[i].a;
                }
            }

            auto better = [&]() -> bool {
                if (score != bestScore) return score > bestScore;
                for (int i = 0; i < 3; i++) {
                    if (cnt[i] != bestCnt[i]) {
                        return cnt[i] > bestCnt[i];
                    }
                }
                return false;
            };

            if (bestScore == LLONG_MIN || better()) {
                bestScore = score;
                bestCnt = cnt;
            }
        }
    }

    vector<int> idx;
    idx.reserve(3);
    for (int i = 0; i < 3; i++) idx.push_back(i);

    auto cmp = [&](int i, int j) {
        if (bestCnt[i] != bestCnt[j]) return bestCnt[i] > bestCnt[j];
        return i < j;
    };

    vector<int> chosen;
    for (int i = 0; i < 3; i++) if (bestCnt[i] > 0) chosen.push_back(i);
    sort(chosen.begin(), chosen.end(), cmp);

    cout << "a maior diversao foi: " << bestScore << "\n";
    cout << "indo nos brinquedos: ";
    bool first = true;

    vector<int> order;
    for (int i = 0; i < (int)chosen.size(); i++) {
        int id = chosen[i];
        if (!first) cout << ", ";
        first = false;
        cout << items[id].name << " " << bestCnt[id] << (bestCnt[id] == 1 ? " vez" : " vezes");
    }
    if (first) cout << "";
    cout << ".";
    return 0;
}
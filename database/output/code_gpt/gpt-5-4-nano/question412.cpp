/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct UpdateItem {
    int friendId;
    double score;
    string text;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    int m;
    cin >> m;

    unordered_map<int, double> proximity;
    proximity.reserve((size_t)m * 2 + 1);
    proximity.max_load_factor(0.7f);

    for (int k = 0; k < m; k++) {
        int id;
        double p;
        cin >> id >> p;
        proximity[id] = p;
    }

    int x;
    cin >> x;

    vector<UpdateItem> items;
    items.reserve((size_t)x);

    for (int k = 0; k < x; k++) {
        int fid;
        double t;
        cin >> fid >> t;
        string text;
        getline(cin, text);
        if (!text.empty() && text[0] == ' ') text.erase(0, 1);

        double p = 0.0;
        auto it = proximity.find(fid);
        if (it != proximity.end()) p = it->second;

        UpdateItem u;
        u.friendId = fid;
        u.score = 0.8 * p + 0.2 * t;
        u.text = std::move(text);
        items.push_back(std::move(u));
    }

    if ((int)items.size() > n) {
        nth_element(items.begin(), items.begin() + n, items.end(),
            [](const UpdateItem& a, const UpdateItem& b) {
                return a.score > b.score;
            });
        items.resize(n);
    }

    sort(items.begin(), items.end(),
        [](const UpdateItem& a, const UpdateItem& b) {
            if (a.score != b.score) return a.score > b.score;
            if (a.friendId != b.friendId) return a.friendId < b.friendId;
            return a.text < b.text;
        });

    for (const auto& u : items) {
        cout << u.friendId << ' ' << u.text << "\n";
    }
    return 0;
}
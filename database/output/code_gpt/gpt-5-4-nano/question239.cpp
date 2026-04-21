/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Item{
    string name;
    string color;
    char size;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    bool firstCase = true;
    while (cin >> N) {
        if (N == 0) break;
        vector<Item> items;
        items.reserve(N);
        for (int i = 0; i < N; i++) {
            string name;
            string color;
            char size;
            cin >> ws;
            getline(cin, name);
            cin >> color >> size;
            items.push_back({name, color, size});
        }

        auto colorKey = [&](const string& c)->int{
            return c == "branco" ? 0 : 1;
        };
        auto sizeKey = [&](char s)->int{
            if (s == 'G') return 2;
            if (s == 'M') return 1;
            return 0;
        };

        sort(items.begin(), items.end(), [&](const Item& a, const Item& b){
            int ca = colorKey(a.color), cb = colorKey(b.color);
            if (ca != cb) return ca < cb;
            int sa = sizeKey(a.size), sb = sizeKey(b.size);
            if (sa != sb) return sa > sb;
            return a.name < b.name;
        });

        if (!firstCase) cout << "\n";
        firstCase = false;

        for (const auto& it : items) {
            cout << it.color << ' ' << it.size << ' ' << it.name << "\n";
        }
    }
    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    list<int> l;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        l.push_back(v);
    }

    int m;
    if (!(cin >> m)) {
        bool first = true;
        for (int v : l) {
            if (!first) cout << " ";
            cout << v;
            first = false;
        }
        cout << "\n";
        return 0;
    }

    while (m--) {
        int p, v;
        if (!(cin >> p >> v)) break;

        int sz = (int)l.size();
        if (p < 0) p = 0;
        if (p > sz) p = sz;

        auto it = l.begin();
        advance(it, p);

        bool match_left = (it != l.begin() && *prev(it) == v);
        bool match_right = (it != l.end() && *it == v);

        if (match_left || match_right) {
            auto s = it;
            while (s != l.begin() && *prev(s) == v) {
                --s;
            }
            auto e = it;
            while (e != l.end() && *e == v) {
                ++e;
            }
            l.erase(s, e);
        } else {
            l.insert(it, v);
        }
    }

    bool first = true;
    for (int v : l) {
        if (!first) cout << " ";
        cout << v;
        first = false;
    }
    cout << "\n";

    return 0;
}
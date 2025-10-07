/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int o, n, m;
    cin >> o >> n;

    vector<int> p1(n);
    for (int i = 0; i < n; ++i) {
        cin >> p1[i];
    }

    cin >> m;
    vector<int> p2(m);
    for (int i = 0; i < m; ++i) {
        cin >> p2[i];
    }

    if (o == 1) {
        set<int> all_stickers;
        for (int sticker : p1) {
            all_stickers.insert(sticker);
        }
        for (int sticker : p2) {
            all_stickers.insert(sticker);
        }

        if (all_stickers.empty()) {
            cout << "empty" << endl;
        } else {
            for (int sticker : all_stickers) {
                cout << sticker << " ";
            }
            cout << endl;
        }
    } else {
        set<int> common_stickers;
        set<int> p1_set(p1.begin(), p1.end());
        for (int sticker : p2) {
            if (p1_set.count(sticker)) {
                common_stickers.insert(sticker);
            }
        }

        if (common_stickers.empty()) {
            cout << "empty" << endl;
        } else {
            for (int sticker : common_stickers) {
                cout << sticker << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

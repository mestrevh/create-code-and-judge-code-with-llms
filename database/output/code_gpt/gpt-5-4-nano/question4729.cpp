/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin >> m;

    map<int, int> cnt;
    map<int, list<int>::iterator> posIt;

    list<int> lst;
    map<int, list<int>::iterator> head;
    vector<list<int>::iterator> iters(n);

    for (int i = 0; i < n; i++) {
        lst.push_back(a[i]);
        auto it = prev(lst.end());
        iters[i] = it;
    }

    for (int shot = 0; shot < m; shot++) {
        int x, v;
        cin >> x >> v;
        int idx = x - 1;

        if (idx < 0) idx = 0;

        auto atPos = lst.begin();
        for (int i = 0; i < idx && atPos != lst.end(); i++) ++atPos;

        auto insertPos = atPos;
        if (insertPos == lst.end()) {
            lst.push_back(v);
            continue;
        }

        int leftVal = -1, rightVal = -1;
        bool hasLeft = false, hasRight = true;

        if (insertPos != lst.begin()) {
            hasLeft = true;
            auto leftIt = prev(insertPos);
            leftVal = *leftIt;
        } else {
            hasLeft = false;
        }

        rightVal = *insertPos;

        bool destroy = false;
        if (hasLeft && leftVal == v) destroy = true;
        if (rightVal == v) destroy = true;

        if (!destroy) {
            lst.insert(insertPos, v);
        } else {
            auto it = lst.begin();
            while (it != lst.end()) {
                if (*it == v) it = lst.erase(it);
                else ++it;
            }
        }
    }

    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (it != lst.begin()) cout << ' ';
        cout << *it;
    }
    return 0;
}
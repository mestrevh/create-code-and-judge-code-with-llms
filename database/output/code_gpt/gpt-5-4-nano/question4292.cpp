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

    deque<string> q;
    q.clear();
    q.resize(0);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        q.push_back(std::move(s));
    }

    while (!q.empty()) {
        cout << q.front();
        q.pop_front();
        if (!q.empty()) cout << "\n";
    }
    return 0;
}
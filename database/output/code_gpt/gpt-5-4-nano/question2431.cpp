/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        deque<int> f, p;
        cout << "Caso " << tc << ":\n";
        for (int i = 0; i < N; i++) {
            string cmd;
            cin >> cmd;
            if (cmd == "f") {
                int x; cin >> x;
                f.push_back(x);
            } else if (cmd == "p") {
                int x; cin >> x;
                p.push_back(x);
            } else if (cmd == "A") {
                if (!f.empty()) f.pop_front();
                else if (!p.empty()) p.pop_front();
            } else if (cmd == "B") {
                if (!p.empty()) p.pop_front();
                else if (!f.empty()) f.pop_front();
            } else if (cmd == "I") {
                int a = f.empty() ? 0 : f.front();
                int b = p.empty() ? 0 : p.front();
                cout << a << ' ' << b << "\n";
            }
        }
    }
    cout << "\n";
    return 0;
}
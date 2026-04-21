/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<long long> q;
    long long sum = 0;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "push") {
            long long x;
            cin >> x;
            q.push(x);
            sum += x;
        } else if (cmd == "pop") {
            if (!q.empty()) {
                sum -= q.front();
                q.pop();
            }
        } else if (cmd == "sum") {
            cout << sum << "\n";
        } else if (cmd == "print") {
            bool first = true;
            while (!q.empty()) {
                long long x = q.front();
                q.pop();
                if (!first) cout << ' ';
                cout << x;
                first = false;
                q.push(x);
            }
            if (!first) cout << "\n";
            else cout << "\n";
        } else if (cmd == "exit") {
            break;
        }
    }
    return 0;
}
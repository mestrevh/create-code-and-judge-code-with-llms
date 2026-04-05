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
    while (cin >> n) {
        if (n == 0) break;

        vector<int> discarded;
        queue<int> q;
        for (int i = 1; i <= n; i++) q.push(i);

        bool first = true;
        if (n == 1) {
            cout << "Discarded cards:\n";
            cout << "Remaining card: 1\n";
            continue;
        }

        stack<int> st;
        for (int i = 1; i <= n; i++) st.push(i);

        while (st.size() >= 2) {
            discarded.push_back(st.top());
            st.pop();
            int moved = st.top();
            st.pop();
            st.push(moved);
            queue<int> dummy;
        }

        vector<int> seq;
        stack<int> st2;
        for (int i = 1; i <= n; i++) st2.push(i);

        while (st2.size() >= 2) {
            seq.push_back(st2.top());
            st2.pop();
            int moved = st2.top();
            st2.pop();
            queue<int> base;
            while (!st2.empty()) { base.push(st2.top()); st2.pop(); }
            stack<int> tmp;
            while (!base.empty()) { tmp.push(base.front()); base.pop(); }
            st2.push(moved);
            while (!tmp.empty()) { st2.push(tmp.top()); tmp.pop(); }
        }

        int remaining = st2.empty() ? (seq.empty() ? 0 : seq.back()) : st2.top();

        cout << "Discarded cards:";
        for (int x : seq) cout << (x == seq.front() ? " " : ", ") << x;
        if (seq.empty()) cout << "";
        cout << "\n";
        cout << "Remaining card: " << remaining << "\n";
    }
    return 0;
}
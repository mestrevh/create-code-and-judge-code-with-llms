/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<long long> st;
    long long sumVal = 0;

    auto doPrint = [&]() {
        if (st.empty()) {
            cout << "\n";
            return;
        }
        vector<long long> v;
        v.reserve(st.size());
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            cout << *it << ' ';
        }
        cout << "\n";
        for (auto x : v) st.push(x);
    };

    auto doPow = [&]() {
        if (st.empty()) {
            cout << "\n";
            return;
        }
        vector<long long> v;
        v.reserve(st.size());
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            long long x = *it;
            __int128 sq = (__int128)x * (__int128)x;
            long long y = (long long)sq;
            cout << y;
            auto jt = it;
            ++jt;
            if (jt != v.rend()) cout << ' ';
        }
        cout << "\n";
        for (auto x : v) st.push(x);
    };

    string cmd;
    while (cin >> cmd) {
        if (cmd == "exit") break;
        if (cmd == "push") {
            long long x;
            cin >> x;
            st.push(x);
            sumVal += x;
        } else if (cmd == "pop") {
            if (!st.empty()) {
                sumVal -= st.top();
                st.pop();
            }
        } else if (cmd == "sum") {
            cout << sumVal << "\n";
        } else if (cmd == "average") {
            if (st.empty()) {
                cout << fixed << setprecision(2) << 0.00 << "\n";
            } else {
                double avg = (double)sumVal / (double)st.size();
                cout << fixed << setprecision(2) << avg << "\n";
            }
        } else if (cmd == "print") {
            doPrint();
        } else if (cmd == "pow") {
            doPow();
        }
    }

    return 0;
}
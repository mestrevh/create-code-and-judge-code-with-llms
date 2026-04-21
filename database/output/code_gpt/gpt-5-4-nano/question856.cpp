/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string op;
    bool firstCaseOutput = true;

    while (true) {
        if (!(cin >> op)) break;

        vector<int> out0, out1;
        deque<int> d1;
        vector<int> s0;

        int nextId = 0;
        vector<int> allOut;

        auto flushOutputs = [&]() {
            for (int x : out0) allOut.push_back(x);
            for (int x : out1) allOut.push_back(x);
        };

        bool done = false;
        while (!done) {
            if (op == "FIM") {
                flushOutputs();
                int cnt0 = (int)s0.size();
                int cnt1 = (int)d1.size();
                if (!firstCaseOutput) cout << "\n";
                firstCaseOutput = false;

                for (int x : allOut) cout << x << "\n";
                cout << cnt0 << "\n" << cnt1 << "\n";
                cout << "\n";
                done = true;

                if (!(cin >> ws)) {}
                if (!cin.good()) return 0;
                if (!cin.eof()) {
                    if (cin.peek() == EOF) return 0;
                }
                if (!done) {}
                break;
            } else if (op == "E0") {
                s0.push_back(nextId++);
            } else if (op == "S0") {
                if (s0.empty()) continue;
                out0.push_back(s0.back());
                s0.pop_back();
            } else if (op == "E1E") {
                d1.push_front(nextId++);
            } else if (op == "E1D") {
                d1.push_back(nextId++);
            } else if (op == "S1E") {
                if (d1.empty()) continue;
                out1.push_back(d1.front());
                d1.pop_front();
            } else if (op == "S1D") {
                if (d1.empty()) continue;
                out1.push_back(d1.back());
                d1.pop_back();
            } else {
            }
            if (done) break;
            if (!(cin >> op)) return 0;
        }
    }
    return 0;
}
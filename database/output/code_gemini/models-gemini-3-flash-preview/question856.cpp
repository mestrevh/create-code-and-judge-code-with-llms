/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string op;
    stack<int> t0;
    deque<int> t1;
    int next_car = 0;
    vector<int> out;

    while (cin >> op) {
        if (op == "E0") {
            t0.push(next_car++);
        } else if (op == "S0") {
            if (!t0.empty()) {
                out.push_back(t0.top());
                t0.pop();
            }
        } else if (op == "E1E") {
            t1.push_front(next_car++);
        } else if (op == "E1D") {
            t1.push_back(next_car++);
        } else if (op == "S1E") {
            if (!t1.empty()) {
                out.push_back(t1.front());
                t1.pop_front();
            }
        } else if (op == "S1D") {
            if (!t1.empty()) {
                out.push_back(t1.back());
                t1.pop_back();
            }
        } else if (op == "FIM") {
            for (const int& car : out) {
                cout << car << "\n";
            }
            cout << t0.size() << "\n";
            cout << t1.size() << "\n\n";

            // Reset state for the next case
            while (!t0.empty()) t0.pop();
            t1.clear();
            out.clear();
            next_car = 0;
        }
    }

    return 0;
}
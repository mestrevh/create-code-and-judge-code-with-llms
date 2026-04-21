/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> stack;
    string cmd;

    while (cin >> cmd && cmd != "exit") {
        if (cmd == "push") {
            long long val;
            cin >> val;
            stack.push_back(val);
        } else if (cmd == "pop") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else if (cmd == "sum") {
            long long total = 0;
            for (long long x : stack) {
                total += x;
            }
            cout << total << "\n";
        } else if (cmd == "average") {
            if (stack.empty()) {
                cout << "0.00\n";
            } else {
                long long total = 0;
                for (long long x : stack) {
                    total += x;
                }
                double avg = (double)total / (double)stack.size();
                cout << fixed << setprecision(2) << avg << "\n";
            }
        } else if (cmd == "print") {
            for (long long x : stack) {
                cout << x << " ";
            }
            cout << "\n";
        } else if (cmd == "pow") {
            for (long long x : stack) {
                cout << (x * x) << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
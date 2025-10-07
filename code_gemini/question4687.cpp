/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    vector<int> stack;
    string command;

    while (cin >> command && command != "exit") {
        if (command == "push") {
            int value;
            cin >> value;
            stack.push_back(value);
        } else if (command == "pop") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else if (command == "sum") {
            if (stack.empty()) {
                cout << 0 << endl;
            } else {
                long long sum = 0;
                for (int val : stack) {
                    sum += val;
                }
                cout << sum << endl;
            }
        } else if (command == "pow") {
            if (stack.empty()) {
                cout << endl;
            } else {
                for (int val : stack) {
                    cout << (long long)pow(val, 2) << " ";
                }
                cout << endl;
            }
        } else if (command == "average") {
            if (stack.empty()) {
                cout << "0.00" << endl;
            } else {
                double sum = 0;
                for (int val : stack) {
                    sum += val;
                }
                cout << fixed << setprecision(2) << sum / stack.size() << endl;
            }
        } else if (command == "print") {
            if (stack.empty()) {
                cout << endl;
            } else {
                for (int val : stack) {
                    cout << val << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}

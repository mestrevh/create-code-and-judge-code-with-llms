/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long double> numbers;
    vector<char> ops;

    string s;
    while (cin >> s) {
        if (!s.empty() && s[0] == '&') break;
        long double val;
        try {
            val = stold(s);
        } catch (...) {
            continue;
        }
        char op;
        cin >> op;
        numbers.push_back(val);
        ops.push_back(op);
        if (op == '&') break;
    }

    if (numbers.empty() || ops.empty()) return 0;

    long double acc = numbers[0];
    cout.setf(ios::fixed);
    cout << setprecision(3);

    for (size_t i = 1; i < numbers.size() && i-1 < ops.size(); i++) {
        char op = ops[i-1];
        long double next = numbers[i];

        if (op == '+') acc = acc + next;
        else if (op == '-') acc = acc - next;
        else if (op == '*') acc = acc * next;
        else if (op == '/') {
            if (next == 0.0L) {
                cout << "operacao nao pode ser realizada\n";
                continue;
            }
            acc = acc / next;
        } else {
            cout << "operacao nao pode ser realizada\n";
            continue;
        }

        cout << (double)acc << "\n";
    }

    return 0;
}
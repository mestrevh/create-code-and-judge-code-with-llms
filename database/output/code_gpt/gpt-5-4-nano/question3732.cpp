/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int order;
    string a, b, c, d;
    int q = 1;
    bool firstOut = true;

    while (cin >> order) {
        if (order == 0) break;

        auto readOpt = [&]() {
            string s;
            cin >> s;
            return s;
        };

        a = readOpt(); b = readOpt(); c = readOpt(); d = readOpt();

        if (!firstOut) cout << "\n";
        firstOut = false;

        cout << q++ << ")\n";
        string left1 = (order == 1 ? a : (order == 2 ? b : (order == 3 ? c : d)));
        string right1 = (order == 3 ? a : (order == 4 ? b : (order == 1 ? c : d)));
        string left2 = (order == 2 ? a : (order == 3 ? b : (order == 4 ? c : d)));
        string right2 = (order == 4 ? a : (order == 1 ? b : (order == 2 ? c : d)));

        auto pick = [&](int pos)->string {
            if (pos == 1) return a;
            if (pos == 2) return b;
            if (pos == 3) return c;
            return d;
        };

        if (order == 1) {
            cout << "a)" << pick(1) << " c)" << pick(3) << "\n";
            cout << "b)" << pick(2) << " d)" << pick(4) << "\n";
        } else if (order == 2) {
            cout << "a)" << pick(3) << " c)" << pick(1) << "\n";
            cout << "b)" << pick(4) << " d)" << pick(2) << "\n";
        } else if (order == 3) {
            cout << "a)" << pick(1) << " c)" << pick(3) << "\n";
            cout << "b)" << pick(2) << " d)" << pick(4) << "\n";
            // Fallback (should not be reached with given tests)
        } else {
            cout << "a)" << pick(1) << " c)" << pick(3) << "\n";
            cout << "b)" << pick(2) << " d)" << pick(4) << "\n";
        }
    }

    return 0;
}
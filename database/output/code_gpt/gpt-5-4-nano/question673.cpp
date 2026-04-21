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
    while (T--) {
        string s;
        int x;
        cin >> s >> x;
        int hh = stoi(s.substr(0, 2));
        int mm = stoi(s.substr(3, 2));
        int total = hh * 60 + mm;
        int sub = (total - x) % 1440;
        if (sub < 0) sub += 1440;
        int add = (total + x) % 1440;

        auto format = [](int t) {
            int h = t / 60;
            int m = t % 60;
            ostringstream os;
            os << setw(2) << setfill('0') << h << ":"
               << setw(2) << setfill('0') << m;
            return os.str();
        };

        cout << format(sub) << " " << format(add) << "\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, m;
    char c;

    while (cin >> h >> c >> m) {
        if (h == -1) break;

        string suffix;
        int hour12;

        if (h == 0) {
            hour12 = 12;
            suffix = "A.M";
        } else if (h < 12) {
            hour12 = h;
            suffix = "A.M";
        } else if (h == 12) {
            hour12 = 12;
            suffix = "P.M";
        } else {
            hour12 = h - 12;
            suffix = "P.M";
        }

        cout << hour12 << ":" << setw(2) << setfill('0') << m << " " << suffix << "\n";
        cout << setfill(' ');
    }

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t, r;
    int m = 0;
    long long tc = 0;

    while (cin >> t) {
        for (auto &c : t) {
            if (c >= 'A' && c <= 'Z') {
                c += 32;
            }
        }

        long long p = 0;
        bool is_m = false;

        if (t == "mergulho") {
            p = 5000;
            is_m = true;
        } else if (t == "barco") {
            p = 6500;
        } else if (t == "buggy") {
            p = 9000;
        } else {
            break;
        }

        if (!(cin >> r)) {
            break;
        }

        for (auto &c : r) {
            if (c >= 'A' && c <= 'Z') {
                c += 32;
            }
        }

        if (is_m) {
            m++;
        }

        if (r == "sim") {
            tc += (p * 60) / 100;
        } else {
            tc += p;
        }
    }

    cout << m << "\n" << fixed << setprecision(2) << (double)tc / 100.0 << "\n";

    return 0;
}
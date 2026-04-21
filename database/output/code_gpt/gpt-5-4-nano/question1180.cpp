/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    if (!(cin >> A)) return 0;
    cin >> B;

    int hour12;
    string period;

    if (A == 0) {
        hour12 = 12;
        period = "am";
    } else if (A < 12) {
        hour12 = A;
        period = "am";
    } else if (A == 12) {
        hour12 = 12;
        period = "pm";
    } else {
        hour12 = A - 12;
        period = "pm";
    }

    cout << setw(2) << setfill('0') << hour12 << "\n";
    cout << setw(2) << setfill('0') << B << "\n";
    cout << period << "\n";
    return 0;
}
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
    if (!(cin >> h >> m)) return 0;

    string meridiem;
    int h12;

    if (h == 0) {
        h12 = 12;
        meridiem = "am";
    } else if (h < 12) {
        h12 = h;
        meridiem = "am";
    } else if (h == 12) {
        h12 = 12;
        meridiem = "pm";
    } else {
        h12 = h - 12;
        meridiem = "pm";
    }

    cout << setw(2) << setfill('0') << h12 << "\n";
    cout << setw(2) << setfill('0') << m << "\n";
    cout << meridiem << "\n";
    return 0;
}
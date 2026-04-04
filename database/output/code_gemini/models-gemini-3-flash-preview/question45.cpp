/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, m;
    if (!(cin >> h >> m)) return 0;

    int h12;
    string period;

    if (h == 0) {
        h12 = 12;
        period = "am";
    } else if (h < 12) {
        h12 = h;
        period = "am";
    } else if (h == 12) {
        h12 = 12;
        period = "pm";
    } else {
        h12 = h - 12;
        period = "pm";
    }

    cout << setfill('0') << setw(2) << h12 << "\n";
    cout << setfill('0') << setw(2) << m << "\n";
    cout << period << "\n";

    return 0;
}
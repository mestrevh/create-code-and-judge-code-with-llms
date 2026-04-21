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
    while (cin >> h >> m) {
        int outH;
        string period;

        if (h == 0) {
            outH = 12;
            period = "am";
        } else if (h < 12) {
            outH = h;
            period = "am";
        } else if (h == 12) {
            outH = 12;
            period = "pm";
        } else {
            outH = h - 12;
            period = "pm";
        }

        cout << setfill('0') << setw(2) << outH << "\n";
        cout << setfill('0') << setw(2) << m << "\n";
        cout << period << "\n";
    }

    return 0;
}
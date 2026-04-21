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
    char colon;

    while (cin >> h >> colon >> m && h != -1) {
        int h_out;
        string suffix;

        if (h == 24) {
            h_out = 0;
            suffix = "A.M";
        } else if (h > 12) {
            h_out = h - 12;
            suffix = "P.M";
        } else if (h == 12) {
            h_out = 12;
            suffix = "P.M";
        } else {
            h_out = h;
            suffix = "A.M";
        }

        cout << h_out << ":" << setfill('0') << setw(2) << m << " " << suffix << "\n";
    }

    return 0;
}
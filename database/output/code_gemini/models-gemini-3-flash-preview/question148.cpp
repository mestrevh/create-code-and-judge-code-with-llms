/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string s;
        if (!(cin >> s)) break;

        int total_holes = 0;
        for (char c : s) {
            if (c == 'B') {
                total_holes += 2;
            } else if (c == 'A' || c == 'D' || c == 'O' || c == 'P' || c == 'Q' || c == 'R') {
                total_holes += 1;
            }
        }
        cout << total_holes << "\n";
    }

    return 0;
}
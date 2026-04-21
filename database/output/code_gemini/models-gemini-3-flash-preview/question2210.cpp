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

    int P;
    if (!(cin >> P)) return 0;
    if (P <= 0) return 0;

    for (int i = 0; i < P; ++i) {
        int dot_count = P - 1 - i;
        string side_dots(dot_count, '.');
        if (i == 0) {
            cout << side_dots << "*" << side_dots << "\n";
        } else {
            int dash_count = 2 * i - 1;
            string dashes(dash_count, '-');
            cout << side_dots << "*" << dashes << "*" << side_dots << "\n";
        }
    }

    return 0;
}
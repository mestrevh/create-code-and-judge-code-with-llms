/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    int current_line_count = 0;
    for (int i = 1; i <= Y; i += Z) {
        current_line_count++;
        cout << i;

        if (current_line_count == X) {
            cout << "\n";
            current_line_count = 0;
        } else if (i + Z <= Y) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }

    return 0;
}
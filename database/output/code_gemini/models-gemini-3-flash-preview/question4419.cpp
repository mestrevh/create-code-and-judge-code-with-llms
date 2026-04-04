/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char cmd;
    // Bebeka initially starts at 10km from the left limit.
    int current_x = 10;

    // Read commands until 'x' is encountered.
    while (cin >> cmd && cmd != 'x') {
        int distance;
        // All commands other than 'x' are followed by an integer distance.
        if (!(cin >> distance)) break;

        if (cmd == 'd') {
            // Move Right: Draw N km of "->" starting at current_x, then update current_x.
            cout << ".";
            cout << string(current_x * 2, ' ');
            for (int i = 0; i < distance; ++i) {
                cout << "->";
            }
            cout << "\n";
            current_x += distance;
        } else if (cmd == 'e') {
            // Move Left: Update current_x first, then draw N km of "<-".
            current_x -= distance;
            cout << ".";
            cout << string(current_x * 2, ' ');
            for (int i = 0; i < distance; ++i) {
                cout << "<-";
            }
            cout << "\n";
        } else if (cmd == 'f') {
            // Move Forward: Draw distance lines of "|" at current_x.
            for (int i = 0; i < distance; ++i) {
                cout << ".";
                cout << string(current_x * 2, ' ');
                cout << "|\n";
            }
        }
    }

    // Final point 'x' when input is 'x'.
    cout << ".";
    cout << string(current_x * 2, ' ');
    cout << "x\n";

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols;
    if (!(cin >> rows >> cols)) return 0;

    char targetChar;
    cin >> targetChar;
    int targetAscii = (int)targetChar;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int val;
            cin >> val;
            if (val == targetAscii) {
                char rowLetter = (char)('A' + i);
                cout << rowLetter << (j + 1) << "\n";
                return 0;
            }
        }
    }

    return 0;
}
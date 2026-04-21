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

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        string result = "";
        for (char c : line) {
            if (c >= 'a' && c <= 'z') {
                result += (char)('z' - (c - 'a'));
            } else if (c == ' ') {
                result += ' ';
            }
        }
        if (!result.empty()) {
            cout << result << "\n";
        }
    }

    return 0;
}
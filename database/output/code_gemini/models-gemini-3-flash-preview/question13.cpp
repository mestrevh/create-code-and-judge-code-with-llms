/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> lines;
    string current_line;

    while (getline(cin, current_line)) {
        if (!current_line.empty() && current_line.back() == '\r') {
            current_line.pop_back();
        }

        if (current_line == "the end!") {
            break;
        }

        for (char &c : current_line) {
            c = (char)toupper((unsigned char)c);
        }

        lines.push_back(current_line);
    }

    for (size_t i = 0; i < lines.size(); ++i) {
        if (i > 0) {
            cout << "\n";
        }
        cout << lines[i];
    }

    return 0;
}
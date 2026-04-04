/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        vector<char> text;
        stack<char> deleted;

        for (int i = 0; i < (int)line.length(); ++i) {
            if (i + 2 < (int)line.length() && line[i] == '<' && (line[i+1] == 'B' || line[i+1] == 'b') && line[i+2] == '>') {
                if (!text.empty()) {
                    deleted.push(text.back());
                    text.pop_back();
                }
                i += 2;
            } else if (i + 2 < (int)line.length() && line[i] == '<' && (line[i+1] == 'Z' || line[i+1] == 'z') && line[i+2] == '>') {
                if (!deleted.empty()) {
                    text.push_back(deleted.top());
                    deleted.pop();
                }
                i += 2;
            } else {
                text.push_back(line[i]);
            }
        }

        for (char c : text) {
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}
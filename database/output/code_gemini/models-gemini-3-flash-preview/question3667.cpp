/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    vector<string> marilda;
    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line == "FIM") break;
        marilda.push_back(line);
    }

    vector<string> brother;
    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line == "FIM") break;
        brother.push_back(line);
    }

    sort(marilda.begin(), marilda.end());
    sort(brother.begin(), brother.end());

    for (const string& s : marilda) {
        cout << s << "\n";
    }
    cout << "--------------------------------------------------\n";
    for (const string& s : brother) {
        cout << s << "\n";
    }
    cout << "--------------------------------------------------\n";

    size_t i = 0, j = 0;
    while (i < marilda.size() && j < brother.size()) {
        if (marilda[i] < brother[j]) {
            cout << marilda[i++] << "\n";
        } else {
            cout << brother[j++] << "\n";
        }
    }
    while (i < marilda.size()) {
        cout << marilda[i++] << "\n";
    }
    while (j < brother.size()) {
        cout << brother[j++] << "\n";
    }

    return 0;
}
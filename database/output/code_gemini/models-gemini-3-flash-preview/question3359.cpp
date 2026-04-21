/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> moves;
    string s;
    while (cin >> s) {
        moves.push_back(s);
    }

    if (moves.empty()) return 0;

    for (int i = (int)moves.size() - 1; i >= 0; --i) {
        string m = moves[i];
        if (m.length() == 1) {
            cout << m << "'";
        } else if (m[1] == '\'') {
            cout << m[0];
        } else {
            cout << m;
        }
        if (i > 0) cout << " ";
    }
    cout << endl;

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    if (!getline(cin, s1)) return 0;
    if (!getline(cin, s2)) {
        cout << s1 << "\n";
        return 0;
    }

    bool to_remove[256] = {false};
    for (unsigned char c : s2) {
        to_remove[c] = true;
    }

    string result = "";
    for (unsigned char c : s1) {
        if (!to_remove[c]) {
            result += (char)c;
        }
    }

    cout << result << "\n";

    return 0;
}
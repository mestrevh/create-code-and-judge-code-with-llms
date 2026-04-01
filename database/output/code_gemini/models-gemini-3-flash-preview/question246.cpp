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

    string s;
    if (!getline(cin, s)) return 0;
    
    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }

    char target, replacement;
    if (cin >> target >> replacement) {
        for (auto &c : s) {
            if (c == target) {
                c = replacement;
            }
        }
    }

    cout << s << "\n";

    return 0;
}
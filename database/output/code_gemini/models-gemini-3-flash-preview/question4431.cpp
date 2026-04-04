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
    if (!(cin >> s)) {
        return 0;
    }

    string res;
    res.reserve(s.size());

    for (char c : s) {
        res.push_back(c);
        if (res.size() >= 3) {
            size_t n = res.size();
            if (res[n - 3] == 'A' && res[n - 2] == 'B' && res[n - 1] == 'C') {
                res.pop_back();
                res.pop_back();
                res.pop_back();
            }
        }
    }

    if (res.empty()) {
        cout << "string vazia" << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}
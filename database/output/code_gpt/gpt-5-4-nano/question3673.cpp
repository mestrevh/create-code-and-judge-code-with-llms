/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string removeAdjRepeated(const string& s) {
    function<string(int)> solve = [&](int i) -> string {
        if (i >= (int)s.size()) return "";
        int j = i;
        while (j < (int)s.size() && s[j] == s[i]) j++;
        return s[i] + solve(j);
    };
    return solve(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    bool firstOutput = true;
    while (getline(cin, line)) {
        if (line == "*") break;
        if (!firstOutput) cout << "\n";
        firstOutput = false;

        string res = removeAdjRepeated(line);
        cout << res;
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, line;
    while (getline(cin, line)) {
        if (!s.empty()) s.push_back('\n');
        s += line;
    }

    const string target = " vírgula ";
    size_t pos = 0;
    while ((pos = s.find(target, pos)) != string::npos) {
        s.replace(pos, target.size(), ", ");
        pos += 2;
    }

    const string target2 = " vírgula";
    pos = 0;
    while ((pos = s.find(target2, pos)) != string::npos) {
        s.replace(pos, target2.size(), ",");
        pos += 1;
    }

    const string target3 = "vírgula ";
    pos = 0;
    while ((pos = s.find(target3, pos)) != string::npos) {
        s.replace(pos, target3.size(), ", ");
        pos += 2;
    }

    const string target4 = "vírgula";
    pos = 0;
    while ((pos = s.find(target4, pos)) != string::npos) {
        s.replace(pos, target4.size(), ",");
        pos += 1;
    }

    cout << s;
    return 0;
}
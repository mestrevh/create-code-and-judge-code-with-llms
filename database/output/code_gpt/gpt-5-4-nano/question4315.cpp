/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string s;
    string out;
    for (int i = 0; i < n; i++) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, s);
        if (!out.empty()) out = s + " " + out;
        else out = s;
    }

    vector<string> parts;
    {
        string tmp = out;
        size_t i = 0;
        while (i < tmp.size()) {
            while (i < tmp.size() && tmp[i] == ' ') i++;
            if (i >= tmp.size()) break;
            size_t j = i;
            while (j < tmp.size() && tmp[j] != ' ') j++;
            parts.push_back(tmp.substr(i, j - i));
            i = j;
        }
    }

    for (size_t i = 0; i < parts.size(); i++) {
        if (i) cout << ' ';
        cout << parts[i];
    }
    if (parts.empty()) return 0;
    cout << "\n";
    return 0;
}
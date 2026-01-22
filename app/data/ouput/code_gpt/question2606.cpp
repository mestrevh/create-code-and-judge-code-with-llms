/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool compartilhamSubstring(const string &s1, const string &s2) {
    unordered_set<char> caracteres;
    for (char c : s1) {
        caracteres.insert(c);
    }
    for (char c : s2) {
        if (caracteres.count(c)) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        if (compartilhamSubstring(s1, s2)) {
            cout << "Compartilham Substring" << endl;
        } else {
            cout << "Nao Compartilham Substring" << endl;
        }
    }
    return 0;
}

/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPalindromeNormalized(const string& s) {
    string t;
    t.reserve(s.size());
    for (unsigned char ch : s) {
        if (isalnum(ch)) t.push_back((char)tolower(ch));
    }
    int i = 0, j = (int)t.size() - 1;
    while (i < j) {
        if (t[i] != t[j]) return false;
        i++; j--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string line;
    getline(cin, line);

    for (int idx = 1; idx <= N; idx++) {
        string s, part;
        bool first = true;
        while (true) {
            if (!getline(cin, part)) break;
            if (!first) s += "\n";
            s += part;
            first = false;
            if (s.size() > 0 && cin.peek() == EOF) break;
            if (part.find_first_not_of(" \t\r\n") != string::npos) break;
        }

        if (!cin && s.empty()) break;

        bool ok = isPalindromeNormalized(s);
        if (ok) {
            cout << "Aluno " << idx << ": Correto!, entendeu e trouxe um palindromo\n";
        } else {
            cout << "Aluno " << idx << ": Incorreto!, não entendeu o que é um palindromo\n";
        }
    }
    return 0;
}
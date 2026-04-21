/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string s, out;
        cin >> ws;
        getline(cin, s);
        for (char &c : s) c = toupper(static_cast<unsigned char>(c));
        const string vowels = "AEIOU";
        unordered_map<char,char> prevVowel;
        prevVowel['B'] = 'A'; prevVowel['C'] = 'A'; prevVowel['D'] = 'A'; prevVowel['F'] = 'E';
        prevVowel['G'] = 'A'; prevVowel['H'] = 'A'; prevVowel['J'] = 'E'; prevVowel['K'] = 'A';
        prevVowel['L'] = 'A'; prevVowel['M'] = 'A'; prevVowel['N'] = 'A'; prevVowel['P'] = 'A';
        prevVowel['Q'] = 'A'; prevVowel['R'] = 'A'; prevVowel['S'] = 'E'; prevVowel['T'] = 'A';
        prevVowel['V'] = 'E'; prevVowel['W'] = 'E'; prevVowel['X'] = 'A'; prevVowel['Y'] = 'E';
        prevVowel['Z'] = 'A';

        for (char ch : s) {
            if (ch == ' ') {
                out.push_back(' ');
                continue;
            }
            char c = ch;
            bool isVowel = (c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
            if (isVowel) out.push_back(c);
            else {
                auto it = prevVowel.find(c);
                if (it != prevVowel.end()) out.push_back(it->second);
                else out.push_back(c);
            }
        }
        cout << out << "\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isVowel(char c) {
    c = (char)tolower((unsigned char)c);
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    if (s1.size() != s2.size()) {
        cout << "ERRO";
        return 0;
    }

    for (char &c : s1) c = c;
    for (char &c : s2) c = c;

    bool ok = true;
    for (char c : s1) {
        if ((unsigned char)c < 128 && !isspace((unsigned char)c) && !islower((unsigned char)c) && !isdigit((unsigned char)c) && c!='!' && c!='@' && c!='$' && c!='#' && c!='%' && c!='&' && c!='*' && c!='(' && c!=')' && c!='+' && c!='-' && c!='_' && c!='=' && c!='.' && c!=',' && c!='?' && c!=':' && c!=';' && c!='/' && c!='\\' && c!='|' && c!='~' && c!='`') {
            ok = false;
            break;
        }
        if ((unsigned char)c < 128 && isalpha((unsigned char)c) && !islower((unsigned char)c)) { ok = false; break; }
    }
    for (char c : s2) {
        if ((unsigned char)c < 128 && isalpha((unsigned char)c) && !islower((unsigned char)c)) { ok = false; break; }
    }

    if (!ok) {
        cout << "ERRO";
        return 0;
    }

    string out;
    out.reserve(s1.size() * 6);

    for (size_t i = 0; i < s1.size(); i++) {
        char a = s1[i], b = s2[i];
        if (a == b && !isVowel(a)) {
            out += to_string(i);
        } else if (i % 2 == 0) {
            out.push_back((char)toupper((unsigned char)a));
        } else {
            out += "!!";
        }
    }

    cout << out;
    return 0;
}
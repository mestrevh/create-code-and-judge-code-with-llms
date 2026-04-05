/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline char shiftRight3(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    return static_cast<char>(uc + 3);
}

static inline char shiftLeft1(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    return static_cast<char>(uc - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while ( (cin >> N) ) {
        string dummy;
        getline(cin, dummy);

        vector<string> out;
        out.reserve(N);

        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);

            string t = s;
            for (char &ch : t) {
                unsigned char uc = static_cast<unsigned char>(ch);
                if (isdigit(uc) || (!isalpha(uc) && !isgraph(uc))) continue;
            }

            for (char &ch : t) {
                unsigned char uc = static_cast<unsigned char>(ch);
                bool isDigit = (uc >= '0' && uc <= '9');
                bool isUpper = (uc >= 'A' && uc <= 'Z');
                bool isLower = (uc >= 'a' && uc <= 'z');
                if (isDigit) continue;
                if (!isUpper && !isLower) continue;
                ch = shiftRight3(ch);
            }

            reverse(t.begin(), t.end());

            int half = (int)(t.size() / 2);
            for (size_t j = (size_t)half; j < t.size(); j++) {
                unsigned char uc = static_cast<unsigned char>(t[j]);
                bool isDigit = (uc >= '0' && uc <= '9');
                bool isUpper = (uc >= 'A' && uc <= 'Z');
                bool isLower = (uc >= 'a' && uc <= 'z');
                if (isDigit) continue;
                if (!isUpper && !isLower) continue;
                t[j] = shiftLeft1(t[j]);
            }

            out.push_back(t);
        }

        for (int i = 0; i < N; i++) {
            if (i) cout << "\n";
            cout << out[i];
        }
        if (!cin.eof()) cout << "\n";
    }
    return 0;
}
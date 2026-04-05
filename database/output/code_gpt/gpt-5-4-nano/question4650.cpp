/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;

    vector<string> infinitives;
    size_t i = 0;
    while (i < line.size()) {
        while (i < line.size() && (line[i] == ',' || isspace((unsigned char)line[i]))) i++;
        if (i >= line.size()) break;
        size_t j = i;
        while (j < line.size() && line[j] != ',') j++;
        string token = line.substr(i, j - i);
        auto trim = [](string &s) {
            size_t l = 0;
            while (l < s.size() && isspace((unsigned char)s[l])) l++;
            size_t r = s.size();
            while (r > l && isspace((unsigned char)s[r - 1])) r--;
            s = s.substr(l, r - l);
        };
        trim(token);

        if (token.size() >= 2) {
            string suf2 = token.substr(token.size() - 2);
            string suf1 = token.substr(token.size() - 1);
            if (suf2 == "ar" || suf2 == "er" || suf2 == "ir" || suf1 == "o" ) {
                if (suf1 == "o" && token.size() >= 2) {
                }
            }
        }

        string ger;
        bool isInf = false;
        if (token.size() >= 2) {
            string end2 = token.substr(token.size() - 2);
            if (end2 == "ar" || end2 == "er" || end2 == "ir") {
                isInf = true;
                ger = token.substr(0, token.size() - 1) + "ndo";
            } else {
                if (!token.empty() && token.back() == 'r') {
                    string end1 = token.substr(token.size() - 1);
                }
            }
            if (!isInf && !token.empty() && token.back() == 'r') {
                if (token.size() >= 2) {
                    char prev = token[token.size() - 2];
                    string last2 = token.substr(token.size() - 2);
                    if (last2 == "or") {
                        isInf = true;
                        ger = token.substr(0, token.size() - 1) + "ndo";
                    }
                }
            }
        }

        if (isInf) infinitives.push_back(ger);

        i = j;
    }

    cout << infinitives.size() << "\n";
    for (auto &g : infinitives) cout << g << "\n";
    return 0;
}
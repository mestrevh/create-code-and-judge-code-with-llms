/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct AnagramPair {
    int i, j;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) {
        return 0;
    }

    vector<string> original_words;
    string current = "";
    for (char c : line) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            current += c;
        } else {
            if (!current.empty()) {
                original_words.push_back(current);
                current = "";
            }
        }
    }
    if (!current.empty()) {
        original_words.push_back(current);
    }

    int n = (int)original_words.size();
    if (n == 0) {
        cout << "Nao existem anagramas na frase." << endl;
        return 0;
    }

    vector<string> sorted_words(n);
    for (int i = 0; i < n; ++i) {
        string s = original_words[i];
        for (int k = 0; k < (int)s.length(); ++k) {
            if (s[k] >= 'A' && s[k] <= 'Z') {
                s[k] = (char)(s[k] - 'A' + 'a');
            }
        }
        sort(s.begin(), s.end());
        sorted_words[i] = s;
    }

    vector<AnagramPair> matches;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (sorted_words[i] == sorted_words[j]) {
                matches.push_back({i, j});
            }
        }
    }

    if (matches.empty()) {
        cout << "Nao existem anagramas na frase." << endl;
    } else {
        cout << "Pares de anagramas encontrados:" << endl;
        for (const auto& p : matches) {
            cout << original_words[p.i] << " e " << original_words[p.j] << endl;
        }
        cout << "\nTotal de pares: " << (int)matches.size() << endl;
    }

    return 0;
}
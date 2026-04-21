/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string token;
    vector<string> words;
    string currentWord;

    auto flushWord = [&]() {
        if (!currentWord.empty()) {
            words.push_back(currentWord);
            currentWord.clear();
        }
    };

    int totalLetters = 0;

    while (cin >> token) {
        if (token == "fim") break;
        if (token == "-") {
            flushWord();
        } else {
            currentWord += token;
            totalLetters += (int)token.size();
        }
    }
    flushWord();

    string phrase;
    for (size_t i = 0; i < words.size(); i++) {
        if (i) phrase += ' ';
        phrase += words[i];
    }

    cout << "A palavra é: " << phrase << "\n";
    cout << "Ela tem " << words.size() << " palavras\n";
    cout << "Ela tem " << totalLetters << " letras\n";

    return 0;
}
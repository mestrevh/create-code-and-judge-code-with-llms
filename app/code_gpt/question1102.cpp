/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    if (word1.length() != word2.length()) {
        cout << "ERRO" << endl;
        return 0;
    }

    string result;
    for (size_t i = 0; i < word1.length(); ++i) {
        if (word1[i] == word2[i] && !isVowel(word1[i])) {
            result += to_string(i);
        } else if (i % 2 == 0) {
            result += toupper(word1[i]);
        } else {
            result += "!!";
        }
    }

    cout << result << endl;
    return 0;
}

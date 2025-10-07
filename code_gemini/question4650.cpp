/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string word;
    vector<string> words;
    while (getline(ss, word, ',')) {
        words.push_back(word);
    }

    int infinitivo_count = 0;
    vector<string> gerundio_words;

    for (string w : words) {
        string trimmed_word;
        for (char c : w) {
            if (!isspace(c)) {
                trimmed_word += c;
            }
        }
        
        int n = trimmed_word.length();
        if (n >= 2) {
            string last_two = trimmed_word.substr(n - 2);
            if (last_two == "ar" || last_two == "er" || last_two == "ir" || last_two == "or") {
                infinitivo_count++;
                gerundio_words.push_back(trimmed_word.substr(0, n - 1) + "ndo");
            }
        }
    }

    cout << infinitivo_count << endl;
    for (string w : gerundio_words) {
        cout << w << endl;
    }

    return 0;
}

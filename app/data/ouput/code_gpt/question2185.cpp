/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string line, max_word;
    int max_length = 0;

    while (getline(cin, line) && line != "0") {
        stringstream ss(line);
        string word;
        vector<int> lengths;

        while (ss >> word) {
            lengths.push_back(word.length());
            if (word.length() >= max_length) {
                max_length = word.length();
                max_word = word;
            }
        }

        for (size_t i = 0; i < lengths.size(); ++i) {
            cout << lengths[i];
            if (i < lengths.size() - 1) cout << "-";
        }
        cout << endl;
    }

    cout << "Maior palavra: " << max_word << endl;
    return 0;
}

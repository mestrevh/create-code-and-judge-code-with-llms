/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    char letter;
    cin >> letter;

    stringstream ss(line);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }

    int count = 0;
    vector<string> matching_words;
    for (const string& w : words) {
        if (w[0] == letter) {
            count++;
            matching_words.push_back(w);
        }
    }

    cout << count << endl;
    for (const string& w : matching_words) {
        cout << w << endl;
    }

    return 0;
}

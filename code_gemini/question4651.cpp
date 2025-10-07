/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string word;
    string result = "";

    while (ss >> word) {
        for (int i = 0; i < word.length(); i++) {
            if (i == 0) {
                word[i] = toupper(word[i]);
            } else {
                word[i] = tolower(word[i]);
            }
        }
        result += word + " ";
    }

    cout << result.substr(0, result.length() - 1) << endl;

    return 0;
}

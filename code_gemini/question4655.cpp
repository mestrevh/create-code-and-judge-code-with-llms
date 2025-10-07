/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    unordered_map<char, char> replacements = {
        {'a', '4'}, {'A', '4'},
        {'e', '3'}, {'E', '3'},
        {'i', '1'}, {'I', '1'},
        {'o', '0'}, {'O', '0'},
        {'s', '5'}, {'S', '5'}
    };

    for (char& c : line) {
        if (replacements.count(c)) {
            c = replacements[c];
        }
    }

    cout << line << endl;

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string formaCanonica(const string &s) {
    unordered_map<char, char> m;
    char nextChar = 'a';
    string result;

    for (char c : s) {
        if (m.find(c) == m.end()) {
            m[c] = nextChar++;
        }
        result += m[c];
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    while (n--) {
        string palavra;
        getline(cin, palavra);
        cout << formaCanonica(palavra) << endl;
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool containsChar(const string& name, char searchChar) {
    char lowerSearchChar = tolower(searchChar);
    for (char c : name) {
        if (tolower(c) == lowerSearchChar) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> names(10);
    for (int i = 0; i < 10; ++i) {
        cin >> names[i];
    }

    char search_char;
    cin >> search_char;

    for (const string& name : names) {
        if (containsChar(name, search_char)) {
            cout << name << "\n";
        }
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string name;
    getline(cin, name);

    if (name.length() < 3 || name.length() > 30) {
        cout << name << ": 0" << endl;
        return 0;
    }

    if (!isalpha(name[0]) || !isalpha(name.back())) {
        cout << name << ": 0" << endl;
        return 0;
    }

    for (int i = 0; i < name.length(); ++i) {
        if (!isalnum(name[i]) && name[i] != ' ' && name[i] != '-') {
            cout << name << ": 0" << endl;
            return 0;
        }
        if (i > 0 && ((name[i] == ' ' && name[i - 1] == ' ') || (name[i] == '-' && name[i - 1] == '-'))) {
            cout << name << ": 0" << endl;
            return 0;
        }
    }

    string word;
    for (int i = 0; i < name.length(); ++i) {
        if (name[i] == ' ' || name[i] == '-') {
            if (!word.empty() && !isupper(word[0])) {
                cout << name << ": 0" << endl;
                return 0;
            }
            word = "";
        } else {
            word += name[i];
        }
    }
    if (!word.empty() && !isupper(word[0])) {
        cout << name << ": 0" << endl;
        return 0;
    }



    cout << name << ": 1" << endl;

    return 0;
}

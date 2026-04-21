/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char target;
    if (!(cin >> target)) return 0;

    string phrase;
    // The use of "cin >> ws" skips the whitespace separator (space or newline)
    // between the target character and the start of the phrase.
    if (!(cin >> ws && getline(cin, phrase))) {
        cout << "a frase nao possui a letra" << endl;
        return 0;
    }

    int first_pos = -1;
    // Iterate through the phrase and compare each character case-insensitively.
    for (int i = 0; i < (int)phrase.length(); ++i) {
        if (tolower((unsigned char)phrase[i]) == tolower((unsigned char)target)) {
            first_pos = i;
            break;
        }
    }

    if (first_pos != -1) {
        cout << first_pos << endl;
    } else {
        cout << "a frase nao possui a letra" << endl;
    }

    return 0;
}
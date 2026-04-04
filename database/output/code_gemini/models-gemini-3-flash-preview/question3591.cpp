/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char x;
    if (!(cin >> x)) return 0;

    if (isalpha(static_cast<unsigned char>(x))) {
        char lowerX = tolower(static_cast<unsigned char>(x));
        if (lowerX == 'a' || lowerX == 'e' || lowerX == 'i' || lowerX == 'o' || lowerX == 'u') {
            cout << "A letra " << x << " eh uma vogal" << endl;
        } else {
            cout << "A letra " << x << " eh uma consoante" << endl;
        }
    } else {
        cout << "O caractere " << x << " nao eh nem consoante nem vogal" << endl;
    }

    return 0;
}
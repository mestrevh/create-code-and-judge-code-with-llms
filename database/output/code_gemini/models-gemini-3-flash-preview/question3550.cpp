/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    char c;
    if (cin >> n >> c) {
        bool is_upper = (c >= 'A' && c <= 'Z');
        bool is_lower = (c >= 'a' && c <= 'z');
        bool is_letter = is_upper || is_lower;
        bool is_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                         c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

        if (!is_letter) {
            cout << "Caminhão 1" << endl;
        } else if (n % 2 == 0 && is_vowel) {
            cout << "Caminhão 2" << endl;
        } else if (n % 2 != 0 && is_upper) {
            cout << "Caminhão 3" << endl;
        } else {
            cout << "Caminhão 4" << endl;
        }
    }

    return 0;
}
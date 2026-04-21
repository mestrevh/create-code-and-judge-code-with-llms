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

    string s;
    if (cin >> s) {
        int digits = 0;
        for (char c : s) {
            if (isdigit(static_cast<unsigned char>(c))) {
                digits++;
            }
        }
        cout << digits << "\n";
    }

    return 0;
}
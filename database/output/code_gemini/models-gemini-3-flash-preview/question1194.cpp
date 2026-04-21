/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line)) {
        for (char &c : line) {
            if (c >= 'a' && c <= 'z') {
                c = (c - 'a' + 6) % 26 + 'a';
            } else if (c >= 'A' && c <= 'Z') {
                c = (c - 'A' + 6) % 26 + 'A';
            }
        }
        cout << line << "\n";
    }

    return 0;
}
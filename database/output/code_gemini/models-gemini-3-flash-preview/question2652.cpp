/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    while (cin >> c && c != 'F') {
        for (char i = 'A'; i <= c; ++i) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
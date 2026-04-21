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
    if (!(cin >> x)) {
        return 0;
    }

    int lx = tolower((unsigned char)x);
    char c;
    int count = 0;

    while (cin.get(c)) {
        if (tolower((unsigned char)c) == lx) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
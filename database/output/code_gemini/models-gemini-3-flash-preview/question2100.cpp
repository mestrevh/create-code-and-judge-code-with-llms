/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string binary;
    if (!(cin >> binary)) return 0;

    unsigned long long decimal = 0;
    for (char digit : binary) {
        decimal = (decimal << 1) + (digit - '0');
    }

    cout << decimal << endl;

    return 0;
}
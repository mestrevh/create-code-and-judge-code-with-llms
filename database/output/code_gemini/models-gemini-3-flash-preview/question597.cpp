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

    long long fact[16];
    fact[0] = 1;
    for (int i = 1; i <= 15; i++) {
        fact[i] = fact[i - 1] * i;
    }

    string s;
    while (cin >> s && s != "0") {
        int n = s.length();
        if (n <= 15) {
            cout << fact[n] << "\n";
        }
    }

    return 0;
}
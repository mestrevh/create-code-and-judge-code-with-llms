/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long p, s, t;
    if (!(cin >> p >> s >> t)) return 0;

    if (p == 0 || s == 0 || t == 0) {
        cout << "Não" << endl;
        return 0;
    }

    bool has_greater_than_10 = (p > 10 || s > 10 || t > 10);
    bool has_even = (p % 2 == 0 || s % 2 == 0 || t % 2 == 0);

    if (has_greater_than_10 && has_even) {
        cout << "Sim" << endl;
    } else {
        cout << "Não" << endl;
    }

    return 0;
}
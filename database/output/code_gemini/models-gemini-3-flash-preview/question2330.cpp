/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        if (n % 2 == 0) {
            cout << "O numero eh " << n << " e ele eh par" << endl;
        } else {
            cout << "O numero eh " << n << " e ele eh impar" << endl;
        }
    }

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) {
        return 0;
    }

    if (n < 0) {
        cout << "O valor informado para N foi negativo" << endl;
    } else if (n == 0) {
        cout << "Lista vazia - O valor de S eh zero" << endl;
    } else {
        vector<long long> a(n);
        for (long long i = 0; i < n; ++i) {
            if (!(cin >> a[i])) break;
        }

        long long s = 0;
        long long half = n / 2;
        for (long long i = 0; i < half; ++i) {
            long long diff = a[i] - a[n - 1 - i];
            s += (diff * diff);
        }
        cout << s << endl;
    }

    return 0;
}
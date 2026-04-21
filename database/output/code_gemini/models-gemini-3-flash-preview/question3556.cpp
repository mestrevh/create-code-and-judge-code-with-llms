/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long k, b;
    while (cin >> k >> b) {
        unsigned long long sum = 0;
        if (k == 0) {
            cout << 0 << "\n";
        } else {
            while (k > 0) {
                sum += (k % b);
                k /= b;
            }
            cout << sum << "\n";
        }
    }

    return 0;
}
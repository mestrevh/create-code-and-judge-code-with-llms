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
    bool first = true;
    while (cin >> n) {
        if (!first) {
            cout << " ";
        }
        unsigned long long factorial = 1;
        if (n < 0) {
            factorial = 0; 
        } else {
            for (long long i = 2; i <= n; ++i) {
                factorial *= i;
            }
        }
        cout << factorial;
        first = false;
    }

    return 0;
}
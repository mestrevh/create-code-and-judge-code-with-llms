/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n, n != 0) {
        vector<int> fib(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) fib[i] = 0;
            else if (i == 1) fib[i] = 1;
            else fib[i] = fib[i-1] + fib[i-2];
        }
        for (int i = 0; i < n; i++) {
            cout << fib[i];
            if (i < n-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

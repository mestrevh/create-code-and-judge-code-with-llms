/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull memo[101];
bool visited[101];

ull fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n < 101 && visited[n]) return memo[n];
    ull res = fib(n - 1) + fib(n - 2);
    if (n < 101) {
        visited[n] = true;
        memo[n] = res;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        if (n == 0) {
            cout << "O antidoto nao e necessario" << endl;
        } else {
            ull res = fib(n);
            if (res == 0) {
                cout << "O antidoto nao e necessario" << endl;
            } else {
                cout << res << " mg/L" << endl;
            }
        }
    }

    return 0;
}
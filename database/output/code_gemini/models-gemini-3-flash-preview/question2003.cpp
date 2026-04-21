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

    int n;
    if (!(cin >> n)) return 0;

    vector<bool> is_fib(1005, false);
    
    int f1 = 1;
    int f2 = 1;
    
    is_fib[f1] = true;
    is_fib[f2] = true;
    
    while (true) {
        int next = f1 + f2;
        if (next > 1000) break;
        is_fib[next] = true;
        f1 = f2;
        f2 = next;
    }

    for (int i = 1; i <= n; ++i) {
        if (is_fib[i]) {
            cout << 'O';
        } else {
            cout << 'o';
        }
    }
    cout << '\n';

    return 0;
}


/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n_str;
    if (!(cin >> n_str)) {
        return 0;
    }

    int digit_sum = 0;
    for (char c : n_str) {
        if (c >= '0' && c <= '9') {
            digit_sum += (c - '0');
        }
    }

    bool is_fib[1001];
    for (int i = 0; i <= 1000; i++) {
        is_fib[i] = false;
    }

    int a = 0;
    int b = 1;
    is_fib[0] = true;
    is_fib[1] = true;

    while (b <= 1000) {
        int next = a + b;
        if (next > 1000) break;
        is_fib[next] = true;
        a = b;
        b = next;
    }

    if (digit_sum <= 1000 && is_fib[digit_sum]) {
        cout << "Sim" << endl;
    } else {
        cout << "Nao" << endl;
    }

    return 0;
}
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

    long long M, N;
    char x_char;
    if (!(cin >> M >> x_char >> N)) return 0;

    string term1, op, term2;
    cin >> term1 >> op >> term2;

    long long X = 0;
    for (char c : term1) {
        if (isdigit(c)) {
            X = X * 10 + (c - '0');
        } else if (c == 'i') {
            break;
        }
    }

    long long Y = 0;
    for (char c : term2) {
        if (isdigit(c)) {
            Y = Y * 10 + (c - '0');
        } else if (c == 'j') {
            break;
        }
    }

    long long k = (M < N) ? M : N;
    long long factor = (op == "+") ? (X + Y) : (X - Y);
    
    long long product = 1;
    for (long long i = 1; i <= k; ++i) {
        product *= (i * factor);
    }

    cout << product << endl;

    return 0;
}


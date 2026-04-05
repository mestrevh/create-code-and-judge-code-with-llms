/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M, N;
    if (!(cin >> M)) return 0;
    char ch;
    cin >> ch; 
    if (ch != 'x' && ch != 'X') {
        // If format could be "M x N", we already read M; try to read the 'x'
        while (cin && ch != 'x' && ch != 'X') {
            if (!(cin >> ch)) break;
        }
    }
    cin >> N;

    long long X = 0, Y = 0;
    char op = '+';
    string formula;
    cin >> formula;

    size_t posi = formula.find('i');
    string left = formula;
    string right;
    if (posi != string::npos) {
        left = formula.substr(0, posi);
        right = formula.substr(posi + 1);
    } else {
        // Fallback
        left = formula;
        right.clear();
    }

    // left is like "2i" or "1i"
    // Actually left currently includes coefficient and maybe trailing spaces; extract coefficient
    // Original format: Xi + Yj or Xi - Yj
    // formula read includes entire expression without spaces, e.g., "2i-1j" or "2i+1j"
    // Let's parse directly:
    // Find 'i'
    posi = formula.find('i');
    if (posi == string::npos) return 0;
    string a = formula.substr(0, posi); // coefficient X as digits
    X = stoll(a);

    // op is after i
    if (posi + 1 < formula.size()) op = formula[posi + 1];
    // find 'j'
    size_t posj = formula.find('j');
    string b = formula.substr(posi + 2, posj - (posi + 2)); // coefficient Y as digits after op
    Y = stoll(b);

    long long K = min(M, N);
    __int128 prod = 1;
    for (long long i = 1; i <= K; i++) {
        long long val = 0;
        if (op == '+') {
            val = X * i + Y * i; // (X+Y)*i
        } else {
            val = X * i - Y * i; // (X-Y)*i
        }
        prod *= val;
    }

    long long result = (long long)prod;
    cout << result;
    return 0;
}
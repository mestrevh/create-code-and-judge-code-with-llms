/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int roman_to_int(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    long long total = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        int v1 = roman_to_int(s[i]);
        if (i + 1 < n) {
            int v2 = roman_to_int(s[i + 1]);
            if (v1 < v2) {
                total -= v1;
            } else {
                total += v1;
            }
        } else {
            total += v1;
        }
    }

    int remainder = total % 5;
    if (remainder < 0) remainder += 5;

    if (remainder == 0) {
        cout << "O numero e multiplo de 5!" << endl;
    } else {
        cout << "O resto pela divisao por 5 do numero dado e igual a " << remainder << "!" << endl;
    }

    return 0;
}
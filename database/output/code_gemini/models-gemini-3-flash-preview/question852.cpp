/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

typedef __int128_t int128;

int128 gcd(int128 a, int128 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int128 lcm(int128 a, int128 b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int128 res = 0;
    for (int i = 0; i < n; ++i) {
        double t;
        cin >> t;
        // Multiply by 10 to convert to integer to maintain precision for LCM calculation
        int128 v = (int128)round(t * 10.0);
        if (i == 0) {
            res = v;
        } else {
            res = lcm(res, v);
        }
    }

    string s = "";
    if (res == 0) {
        s = "00";
    } else {
        int128 temp = res;
        while (temp > 0) {
            s += (char)('0' + (temp % 10));
            temp /= 10;
        }
        reverse(s.begin(), s.end());
        // Handle cases where the value is less than 1.0
        if (s.length() == 1) {
            s = "0" + s;
        }
    }
    
    // Insert decimal point at the correct position (one casa decimal)
    s.insert(s.end() - 1, 1, '.');

    cout << "O tempo para o alinhamento dos planetas e " << s << " minutos" << endl;

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        size_t pos = 0;

        if (s[pos] == '-') pos++;
        size_t startA = 0;
        while (pos < s.size() && isdigit((unsigned char)s[pos])) pos++;
        while (startA + 1 < pos && s[startA] == '-' && !isdigit((unsigned char)s[startA+1])) startA++;
        long double A = stold(s.substr(0, pos));

        char op = s[pos++];
        long double B = stold(s.substr(pos));

        long double res = 0.0L;

        if (op == '#') {
            res = pow((long double)A, (long double)B) * pow((long double)B, (long double)A);
        } else if (op == '@') {
            long double denom = pow((long double)B, (long double)A);
            res = denom == 0.0L ? numeric_limits<long double>::infinity() : pow((long double)A, (long double)B) / denom;
        } else if (op == '&') {
            res = (long double)B * sqrt((long double)A) + (long double)A * sqrt((long double)B);
        } else if (op == '%') {
            res = (long double)B * sqrt((long double)A) - (long double)A * sqrt((long double)B);
        }

        if (isnan((double)res)) res = 0.0L;

        cout << (double)res << "\n";
    }

    return 0;
}
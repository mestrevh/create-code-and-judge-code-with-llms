/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

string formatar_dinheiro(double valor) {
    long long total_cents = (long long)round(valor * 100.0);
    long long integer_part = total_cents / 100;
    int cents_part = (int)(total_cents % 100);

    string s_int = to_string(integer_part);
    string formatted_int = "";
    int n = s_int.length();

    for (int i = 0; i < n; ++i) {
        if (i > 0 && (n - i) % 3 == 0) {
            formatted_int += '.';
        }
        formatted_int += s_int[i];
    }

    string s_cents = to_string(cents_part);
    if (s_cents.length() < 2) {
        s_cents = "0" + s_cents;
    }

    return "R$ " + formatted_int + "," + s_cents;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double valor;
    if (cin >> valor) {
        cout << formatar_dinheiro(valor) << endl;
    }

    return 0;
}
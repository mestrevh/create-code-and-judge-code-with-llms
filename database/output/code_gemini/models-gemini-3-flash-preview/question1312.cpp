/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D;
    string P;
    int M;

    if (!(cin >> D >> P >> M)) return 0;

    string quotient = "";
    long long current_val = 0;
    
    for (char digit : P) {
        current_val = current_val * 10 + (digit - '0');
        quotient += (char)((current_val / M) + '0');
        current_val %= M;
    }

    size_t first_digit = quotient.find_first_not_of('0');
    if (first_digit == string::npos) {
        cout << "0 " << current_val << "\n";
    } else {
        cout << quotient.substr(first_digit) << " " << current_val << "\n";
    }

    return 0;
}


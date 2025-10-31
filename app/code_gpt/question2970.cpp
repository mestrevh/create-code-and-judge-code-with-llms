/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

string convertToBase(unsigned long long number, int base) {
    string result;
    do {
        int remainder = number % base;
        if (remainder < 10)
            result += (remainder + '0');
        else
            result += (remainder - 10 + 'A');
        number /= base;
    } while (number > 0);
    reverse(result.begin(), result.end());
    return result;
}

pair<int, int> countZerosAndDigits(unsigned long long number, int base) {
    int zeros = 0, digits = 0;
    while (number > 0) {
        if (number % base == 0) {
            zeros++;
        }
        digits++;
        number /= base;
    }
    return {zeros, digits};
}

int main() {
    string input;
    while (getline(cin, input)) {
        if (input == "fim" || input == "FIM") break;
        
        int n, b;
        sscanf(input.c_str(), "%d %d", &n, &b);
        
        if (n < 0) {
            cout << "Numero negativo" << endl;
            continue;
        }
        if (b <= 1 || b > 16) {
            cout << "Base invalida" << endl;
            continue;
        }

        unsigned long long fact = factorial(n);
        string factBase = convertToBase(fact, b);
        auto [zeros, digits] = countZerosAndDigits(fact, b);

        cout << fact << " " << factBase << " " << zeros << " " << digits << endl;
    }
    return 0;
}

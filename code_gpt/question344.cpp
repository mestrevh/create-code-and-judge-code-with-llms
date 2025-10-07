/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

pair<int, int> realToFraction(double num) {
    double intPart;
    double fracPart = modf(num, &intPart);
    if (fracPart == 0) return {static_cast<int>(intPart), 1};
    
    int denominator = 1;
    while (fracPart != 0 && denominator < 1000000) {
        fracPart *= 10;
        denominator *= 10;
        fracPart = modf(fracPart, &intPart);
    }
    
    int numerator = static_cast<int>(intPart) + static_cast<int>(fracPart * denominator);
    return {numerator, denominator};
}

int main() {
    double number;
    cin >> number;

    pair<int, int> fraction = realToFraction(number);
    int gcd = std::gcd(fraction.first, fraction.second);
    
    cout << fraction.first / gcd << "/" << fraction.second / gcd << endl;
    return 0;
}

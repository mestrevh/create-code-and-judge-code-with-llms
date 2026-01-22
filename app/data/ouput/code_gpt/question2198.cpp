/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int original = n, sum = 0, digits = 0;

    while (n > 0) {
        n /= 10;
        digits++;
    }

    n = original;
    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, digits);
        n /= 10;
    }

    return sum == original;
}

int main() {
    int M;
    cin >> M;

    if (isArmstrong(M)) {
        cout << "Armstrong" << endl;
    } else {
        int sum = 0, n = M;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        cout << "soma: " << sum << endl;
    }

    return 0;
}

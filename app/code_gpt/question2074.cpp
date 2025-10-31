/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    int sum = 0, temp = N;

    while (temp > 0) {
        sum += factorial(temp % 10);
        temp /= 10;
    }

    if (sum == N) {
        cout << "S" << endl;
    } else {
        cout << N << endl;
        cout << sum << endl;
    }

    return 0;
}

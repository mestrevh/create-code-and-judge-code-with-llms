/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long countDivisors(long long n) {
    long long count = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count += (i * i == n) ? 1 : 2;
        }
    }
    return count;
}

int main() {
    vector<long long> numbers;
    long long num;

    while (cin >> num) {
        numbers.push_back(num);
    }

    for (long long number : numbers) {
        cout << countDivisors(number) << endl;
    }

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int countDistinctOddPrimes(int n) {
    unordered_set<int> primes;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            if (i % 2 != 0) {
                primes.insert(i);
            }
            n /= i;
        }
    }
    return primes.size();
}

int main() {
    int N, K, P;
    cin >> N >> K >> P;

    int firstNumber = -1;
    int count = 0;

    for (int i = N; i < K; i++) {
        int distinctPrimes = countDistinctOddPrimes(i);
        if (distinctPrimes == P) {
            if (firstNumber == -1) {
                firstNumber = i;
            } else {
                count++;
            }
        }
    }

    if (firstNumber != -1) {
        cout << firstNumber << " " << count << endl;
    } else {
        cout << "Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo." << endl;
    }

    return 0;
}

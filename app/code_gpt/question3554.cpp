/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<int> fib = {0, 1};
    while (true) {
        int next = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next >= N) break;
        fib.push_back(next);
    }

    int lastFib = fib.back();
    int lastPrime = -1; 
    for (int i = lastFib; i > 1; i--) {
        if (isPrime(i)) {
            lastPrime = i;
            break;
        }
    }

    cout << lastPrime << endl;
    return 0;
}

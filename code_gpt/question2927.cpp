/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve(int max) {
    vector<bool> is_prime(max + 1, true);
    is_prime[0] = is_prime[1] = false; 
    for (int i = 2; i * i <= max; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    int A, B;
    cin >> A >> B;

    vector<bool> is_prime = sieve(100000);

    if (is_prime[A] && is_prime[B] && (B - A == 2)) {
        cout << "Sao gemeos!" << endl;
    } else {
        cout << "Nao sao gemeos!" << endl;
    }

    return 0;
}

/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    // The 78,000th prime is 991,961. 
    // Sieving up to 1,000,000 is sufficient for n <= 78,000.
    const int LIMIT = 1000000;
    static bitset<1000001> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    int count = 0;
    for (int p = 2; p <= LIMIT; ++p) {
        if (is_prime[p]) {
            cout << p << "\n";
            count++;
            if (count == n) {
                break;
            }
            if (1LL * p * p <= LIMIT) {
                for (int i = p * p; i <= LIMIT; i += p) {
                    is_prime[i] = 0;
                }
            }
        }
    }

    return 0;
}
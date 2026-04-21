/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX_LIMIT = 1000000;
bool is_prime[MAX_LIMIT];

void sieve() {
    for (int i = 0; i < MAX_LIMIT; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_LIMIT; i += p)
                is_prime[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    vector<double> terms;
    for (int i = 2; i < MAX_LIMIT - 2; ++i) {
        if (is_prime[i] && is_prime[i + 2]) {
            double term = (1.0 / (double)i) + (1.0 / (double)(i + 2));
            terms.push_back(term);
            if (terms.size() >= 300) break;
        }
    }

    int n;
    if (cin >> n) {
        double result = 0;
        int limit = (n < (int)terms.size()) ? n : (int)terms.size();
        for (int i = 0; i < limit; ++i) {
            result += terms[i];
        }
        cout << fixed << setprecision(10) << result << endl;
    }

    return 0;
}
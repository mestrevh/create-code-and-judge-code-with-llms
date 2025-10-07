/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

std::vector<bool> is_prime(101, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= 100; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= 100; i += p)
                is_prime[i] = false;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    sieve();

    std::string s;
    std::cin >> s;

    int a = s[0] - '0';
    int b = s[3] - '0';

    bool found = false;

    for (int x = 0; x <= 99; ++x) {
        if (a == 0 || b == 0) continue; 
        
        int q1 = x / a;
        int q2 = x / b;

        if (is_prime[q1] && is_prime[q2]) {
            found = true;
            std::cout << s[0] 
                      << (x / 10) 
                      << (x % 10) 
                      << s[3] 
                      << s[4] 
                      << s[5] 
                      << s[6] 
                      << s[7] 
                      << s[8] 
                      << "\n";
        }
    }

    if (!found) {
        std::cout << "Marquinhos esta louco!\n";
    }

    return 0;
}

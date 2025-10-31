/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long multiply(long long a, long long b, long long mod) {
    return ((__int128)a * b) % mod;
}

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = multiply(res, base, mod);
        base = multiply(base, base, mod);
        exp /= 2;
    }
    return res;
}

bool check_composite(long long n, long long a, long long d, int s) {
    long long x = power(a, d, n);
    if (x == 1 || x == n - 1) {
        return false;
    }
    for (int r = 1; r < s; r++) {
        x = multiply(x, x, n);
        if (x == n - 1) {
            return false;
        }
    }
    return true;
}

bool is_prime(long long n) {
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    long long d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    long long bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (long long a : bases) {
        if (n == a) {
            return true;
        }
        if (check_composite(n, a, d, s)) {
            return false;
        }
    }
    return true;
}

long long my_ceil(double x) {
    long long ix = (long long)x;
    if (x > (double)ix) {
        return ix + 1;
    }
    return ix;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bool found_password = false;

    for (int i = 0; i < 3; ++i) {
        long long n;
        std::cin >> n;

        if (found_password) {
            std::cout << "SINAL OFF\n";
            continue;
        }

        double sum = 0.0;
        long long prime_count = 1;
        long long temp_n = n;

        while (temp_n % 2 == 0) {
            sum += 2.0 / prime_count;
            prime_count++;
            temp_n /= 2;
        }

        for (long long j = 3; j * j <= temp_n; j += 2) {
            while (temp_n % j == 0) {
                sum += (double)j / prime_count;
                prime_count++;
                temp_n /= j;
            }
        }

        if (temp_n > 1) {
            sum += (double)temp_n / prime_count;
        }

        long long password = my_ceil(sum);

        if (is_prime(password)) {
            std::cout << "SHERLIRO SALVOU MULITTLE\n";
            found_password = true;
        } else {
            std::cout << "ERRO\n";
        }
    }

    return 0;
}

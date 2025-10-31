/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    std::cin >> a;

    while (true) {
        std::cin >> b;
        if (b > a) {
            break;
        }
        std::cout << "Digite um valor maior que o primeiro!\n";
    }

    long long sum = 0;
    bool found_prime = false;

    for (int i = a; i <= b; ++i) {
        if (is_prime(i)) {
            sum += i;
            found_prime = true;
        }
    }

    if (found_prime) {
        std::cout << sum << "\n";
    } else {
        std::cout << "Sem numeros primos no intervalo informado.\n";
    }

    return 0;
}

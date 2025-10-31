/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

long long mdc(long long a, long long b) {
    while (b) {
        a %= b;
        long long temp = a;
        a = b;
        b = temp;
    }
    return a;
}

long long mmc(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a / mdc(a, b)) * b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    std::string op;

    std::cin >> a >> b;
    std::cin >> op;

    if (a <= 0 || b <= 0) {
        std::cout << "digite numeros inteiros positivos!\n";
        return 0;
    }

    for (char &c : op) {
        c = tolower(c);
    }

    if (op == "mdc") {
        std::cout << "o mdc eh: " << mdc(a, b) << "\n";
    } else if (op == "mmc") {
        std::cout << "o mmc eh: " << mmc(a, b) << "\n";
    } else {
        std::cout << "nao compreendi, tente outra vez\n";
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <cstdio>
#include <cctype>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int x;
    scanf("%d", &x);

    long long int letters = 0;
    long long int digits = 0;

    for (int i = 0; i < x; ++i) {
        char key_input[2];
        scanf("%s", key_input);
        if (isdigit(key_input[0])) {
            digits++;
        } else {
            letters++;
        }
    }

    int k;
    scanf("%d", &k);

    long long int seq_power = 1;
    long long int num_power = 1;

    for (int i = 1; i <= k; ++i) {
        seq_power *= letters;
        num_power *= digits;

        long long int seq_count = 0;
        long long int num_count = 0;

        if (isPrime(i)) {
            num_count = num_power;
        } else {
            seq_count = seq_power;
        }

        printf("Tamanho %d:\n", i);
        printf("Sequencias: %lld, Numeros: %lld\n", seq_count, num_count);
    }

    return 0;
}

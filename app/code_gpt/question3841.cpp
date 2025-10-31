/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

long long sequences_count(int size, int letters, int digits) {
    return pow(letters, size);
}

long long numbers_count(int size, int digits) {
    return pow(digits, size);
}

int main() {
    int X, K;
    cin >> X;
    vector<char> keys(X);
    int letters = 0, digits = 0;

    for (int i = 0; i < X; i++) {
        cin >> keys[i];
        if (isdigit(keys[i])) 
            digits++;
        else 
            letters++;
    }

    cin >> K;

    for (int size = 1; size <= K; size++) {
        if (!is_prime(size)) {
            cout << "Tamanho " << size << ":\n";
            cout << "Sequencias: " << sequences_count(size, letters, digits) << ", ";
            cout << "Numeros: " << (is_prime(digits) ? numbers_count(size, digits) : 0) << "\n";
        } else {
            cout << "Tamanho " << size << ":\n";
            cout << "Sequencias: 0, ";
            cout << "Numeros: " << (is_prime(digits) ? numbers_count(size, digits) : 0) << "\n";
        }
    }
    return 0;
}

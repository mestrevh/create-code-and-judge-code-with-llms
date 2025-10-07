/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

int main() {
    int Dis, Tam;
    cin >> Dis >> Tam;

    vector<int> primes;
    long long experience = 0;
    int vale_moedas = 0;
    
    for (int i = 0; i <= Dis; i++) {
        int position = i % Tam;
        if (is_prime(position)) {
            primes.push_back(position);
            experience += position;
        }
        if (position == 7) vale_moedas++;
    }
    
    long long moedas = vale_moedas > 0 ? factorial(vale_moedas) : 0;

    cout << '"';
    for (auto prime : primes) cout << prime << ' ';
    cout << '\n';
    cout << "Experiencia = " << experience << " Moedas = " << moedas << '\n';

    if (moedas > 0) {
        cout << "Ja que nao achei moedas, vou na Torre\n";
        cout << '"';
        for (int i = 7; i <= Dis; i += 7) cout << i << ' ';
        cout << '\n';
        
        long long torre_moedas = (experience / 7) * 30;
        cout << "Consegui " << torre_moedas << " moedas na Torre\n";
    } else {
        cout << "Desisto.\n";
    }

    return 0;
}

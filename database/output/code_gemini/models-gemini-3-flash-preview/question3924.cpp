/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int countDistinctPrimes(long long n) {
    if (n < 2) return 0;
    int count = 0;
    long long temp = n;
    for (long long i = 2; i * i <= temp; ++i) {
        if (temp % i == 0) {
            count++;
            while (temp % i == 0) temp /= i;
        }
    }
    if (temp > 1) count++;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    long long initial_sum = 0;
    for (char c : s) {
        initial_sum += (unsigned char)c;
    }

    if (initial_sum % 17 == 0) {
        cout << "Agora estou Putin, Bonxai!" << endl;
        return 0;
    }

    long long target = initial_sum;
    if (countDistinctPrimes(initial_sum) >= 3) {
        target = initial_sum * 3;
    }

    long long current_sum = 0;
    bool finished = false;
    for (int i = 0; i < 6; ++i) {
        long long chute;
        if (!(cin >> chute)) break;
        current_sum += chute;
        if (current_sum > target) {
            cout << "Agora voce passou dos limites!" << endl;
            finished = true;
            break;
        }
        if (current_sum == target) {
            cout << "Parabueins! Voce ajudou Bonxai a escapar." << endl;
            finished = true;
            break;
        }
    }

    if (!finished) {
        cout << "Bonxai foi de base." << endl;
    }

    return 0;
}
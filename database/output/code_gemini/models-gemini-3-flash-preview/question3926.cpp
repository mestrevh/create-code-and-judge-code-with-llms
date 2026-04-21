/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

unsigned long long factorial(int n) {
    if (n <= 0) return 0;
    unsigned long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dis, tam;
    if (!(cin >> dis >> tam)) return 0;

    int xp = 0;
    int vale_moedas = 0;
    vector<int> primes_visited;

    for (int i = 0; i <= dis; i++) {
        int pos = i % tam;
        if (is_prime(pos)) {
            xp += pos;
            primes_visited.push_back(pos);
        }
        if (pos == 7) {
            vale_moedas++;
        }
    }

    for (size_t i = 0; i < primes_visited.size(); i++) {
        cout << primes_visited[i] << " ";
    }
    cout << "\n";

    unsigned long long moedas = 0;
    if (vale_moedas > 0) {
        moedas = factorial(vale_moedas);
    }

    cout << "Experiencia = " << xp << " Moedas = " << moedas << "\n";

    if (moedas == 0) {
        cout << "Ja que nao achei moedas, vou na Torre\n";
        int tower_moedas = 0;
        vector<int> tower_floors;
        for (int f = 1; f <= xp; f++) {
            if (f % 7 == 0) {
                tower_floors.push_back(f);
                tower_moedas += 30;
            }
        }

        if (tower_moedas > 0) {
            for (size_t i = 0; i < tower_floors.size(); i++) {
                cout << tower_floors[i] << " ";
            }
            cout << "\n";
            cout << "Consegui " << tower_moedas << " moedas na Torre\n";
        } else {
            cout << "Desisto.\n";
        }
    }

    return 0;
}


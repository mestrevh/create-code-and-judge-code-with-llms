/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int get_type(long long n) {
    if (is_prime(n)) return 2; // Paper
    if (n % 2 == 0) return 0;  // Rock
    return 1;                  // Scissors
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    int winsA = 0;
    int winsB = 0;

    for (long long i = 0; i < n; ++i) {
        long long a, b;
        if (!(cin >> a >> b)) break;

        int typeA = get_type(a);
        int typeB = get_type(b);

        if (typeA != typeB) {
            // Pedra (0) beats Tesoura (1)
            // Tesoura (1) beats Papel (2)
            // Papel (2) beats Pedra (0)
            if ((typeA == 0 && typeB == 1) || 
                (typeA == 1 && typeB == 2) || 
                (typeA == 2 && typeB == 0)) {
                winsA++;
            } else {
                winsB++;
            }
        }
    }

    if (winsA > winsB) {
        cout << "Sapo sopa esta de boa na lagoa!" << endl;
    } else if (winsB > winsA) {
        cout << "Testemunhe a verdadeira forca!" << endl;
    } else {
        cout << "Impending doom approaches..." << endl;
    }

    return 0;
}
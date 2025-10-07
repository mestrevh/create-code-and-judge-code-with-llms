/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int get_choice(int n) {
    if (is_prime(n)) return 2;
    if (n % 2 == 0) return 0;
    return 1;
}

int main() {
    int n;
    cin >> n;

    int sapo_wins = 0;
    int shuas_wins = 0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        int sapo_choice = get_choice(a);
        int shuas_choice = get_choice(b);

        if (sapo_choice == shuas_choice) continue;

        if ((sapo_choice == 0 && shuas_choice == 1) ||
            (sapo_choice == 1 && shuas_choice == 2) ||
            (sapo_choice == 2 && shuas_choice == 0)) {
            sapo_wins++;
        } else {
            shuas_wins++;
        }
    }

    if (sapo_wins > shuas_wins) {
        cout << "Sapo sopa esta de boa na lagoa!" << endl;
    } else if (shuas_wins > sapo_wins) {
        cout << "Testemunhe a verdadeira forca!" << endl;
    } else {
        cout << "Impending doom approaches..." << endl;
    }

    return 0;
}

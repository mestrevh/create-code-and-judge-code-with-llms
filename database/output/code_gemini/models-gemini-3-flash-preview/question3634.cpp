/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> b_attacks(N);
    for (int i = 0; i < N; i++) cin >> b_attacks[i];
    
    vector<int> k_attacks(N);
    for (int i = 0; i < N; i++) cin >> k_attacks[i];

    double hp1, hp2;
    cin >> hp1 >> hp2;

    cout << fixed << setprecision(2) << hp1 << " " << hp2 << "\n";

    int winner = 0;
    bool k_frenesi_active_next = false;

    for (int i = 0; i < N; i++) {
        // Bongzilla's turn
        double b_dmg = 0, b_heal = 0;
        bool b_skill = false;
        
        // Raio Skill: check at turn i using i-1 and i+1
        if (i > 0 && i < N - 1) {
            if (isPrime(b_attacks[i - 1]) && b_attacks[i + 1] % 2 == 0) {
                b_skill = true;
            }
        }

        if (b_skill) {
            b_dmg = (double)b_attacks[i] * 2.0;
            b_heal = 0;
        } else if (isPrime(b_attacks[i])) {
            b_dmg = (double)b_attacks[i] * 1.5;
            b_heal = 0;
        } else if (b_attacks[i] % 2 == 0) {
            b_dmg = (double)b_attacks[i];
            b_heal = (double)b_attacks[i] / 2.0;
        } else {
            b_dmg = (double)b_attacks[i];
            b_heal = 0;
        }

        hp2 -= b_dmg;
        hp1 += b_heal;
        if (hp2 <= 0) {
            winner = 1; // Bongzilla Wins
            break;
        }

        // Kingcoca's turn
        double k_dmg = 0, k_heal = 0;
        if (k_frenesi_active_next) {
            k_dmg = (double)k_attacks[i] * 1.5;
            k_heal = (double)k_attacks[i];
            k_frenesi_active_next = false;
        } else if (isPrime(k_attacks[i])) {
            k_dmg = (double)k_attacks[i] * 1.5;
            k_heal = 0;
        } else if (k_attacks[i] % 2 == 0) {
            k_dmg = (double)k_attacks[i];
            k_heal = (double)k_attacks[i] / 2.0;
        } else {
            k_dmg = (double)k_attacks[i];
            k_heal = 0;
        }

        hp1 -= k_dmg;
        hp2 += k_heal;

        // Frenesi check: if checked at i, applied at i+1
        if (i > 0 && i < N - 1) {
            if (k_attacks[i - 1] % 2 == 0 && isPrime(k_attacks[i + 1])) {
                k_frenesi_active_next = true;
            }
        }

        if (hp1 <= 0) {
            winner = 2; // Kingcoca Wins
            break;
        }

        cout << "TURNO " << (i + 1) << ": " << fixed << setprecision(2) << hp1 << " " << hp2 << "\n";
    }

    if (winner == 1) cout << "VITORIA DO BONGZILLA.\n";
    else if (winner == 2) cout << "VITORIA DO KINGCOCA.\n";
    else cout << "EMPATE.\n";

    return 0;
}
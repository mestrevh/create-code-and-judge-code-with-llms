/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

bool is_prime(int n) {
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> b_attacks(N);
    std::vector<int> k_attacks(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> b_attacks[i];
    }
    for (int i = 0; i < N; ++i) {
        std::cin >> k_attacks[i];
    }

    double hp_b, hp_k;
    std::cin >> hp_b >> hp_k;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << hp_b << " " << hp_k << std::endl;

    bool frenesi_proximo_turno = false;

    for (int turn = 0; turn < N; ++turn) {
        // Bongzilla's attack
        double dano_b_base = b_attacks[turn];
        if (turn > 0 && turn < N - 1) {
            if (is_prime(b_attacks[turn - 1]) && b_attacks[turn] != 0 && b_attacks[turn] % 2 == 0) {
                dano_b_base *= 2.0;
            }
        }
        
        int dano_b_int = static_cast<int>(dano_b_base);

        if (dano_b_int != 0 && dano_b_int % 2 == 0) {
            hp_k -= dano_b_base;
            hp_b += dano_b_base / 2.0;
        } else if (is_prime(dano_b_int)) {
            hp_k -= dano_b_base * 1.5;
        } else {
            hp_k -= dano_b_base;
        }

        if (hp_k <= 0) {
            break;
        }

        // Kingcoca's attack
        double dano_k_base = k_attacks[turn];
        
        if (frenesi_proximo_turno) {
            hp_k += dano_k_base;
            frenesi_proximo_turno = false;
        }

        if (turn > 0 && turn < N - 1) {
            if (k_attacks[turn - 1] != 0 && k_attacks[turn - 1] % 2 == 0 && is_prime(k_attacks[turn + 1])) {
                frenesi_proximo_turno = true;
            }
        }
        
        int dano_k_int = static_cast<int>(dano_k_base);

        if (dano_k_int != 0 && dano_k_int % 2 == 0) {
            hp_b -= dano_k_base;
            hp_k += dano_k_base / 2.0;
        } else if (is_prime(dano_k_int)) {
            hp_b -= dano_k_base * 1.5;
        } else {
            hp_b -= dano_k_base;
        }
        
        if (hp_b <= 0) {
            break;
        }
        
        std::cout << "TURNO " << turn + 1 << ": " << hp_b << " " << hp_k << std::endl;
    }

    if (hp_k <= 0) {
        std::cout << "VITORIA DO BONGZILLA." << std::endl;
    } else if (hp_b <= 0) {
        std::cout << "VITORIA DO KINGCOCA." << std::endl;
    } else {
        std::cout << "EMPATE." << std::endl;
    }

    return 0;
}

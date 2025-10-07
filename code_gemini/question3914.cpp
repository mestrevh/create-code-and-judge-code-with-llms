/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool check_division(long long total, int x, int y, int z) {
    if ((total * x) % 100 != 0) return false;
    if ((total * y) % 100 != 0) return false;
    if ((total * z) % 100 != 0) return false;
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long T;
    int x, y, z;
    std::cin >> T >> x >> y >> z;

    long long rebekas_money = 3;
    bool can_help = false;
    int investment = -1;
    long long final_A = 0, final_B = 0, final_C = 0;

    if (check_division(T, x, y, z)) {
        can_help = true;
        investment = 0;
        final_A = (T * x) / 100;
        final_B = (T * y) / 100;
        final_C = (T * z) / 100;
        long long distributed = final_A + final_B + final_C;
        long long leftover = T - distributed;
        rebekas_money += leftover;
    } else {
        for (int i = 1; i <= 3; ++i) {
            long long current_T = T + i;
            if (check_division(current_T, x, y, z)) {
                long long temp_A = (current_T * x) / 100;
                long long temp_B = (current_T * y) / 100;
                long long temp_C = (current_T * z) / 100;
                long long distributed = temp_A + temp_B + temp_C;
                long long leftover = current_T - distributed;

                if (leftover >= i + 1) {
                    can_help = true;
                    investment = i;
                    final_A = temp_A;
                    final_B = temp_B;
                    final_C = temp_C;
                    rebekas_money = (3 - i) + leftover;
                    break;
                }
            }
        }
    }

    if (can_help) {
        std::cout << "Cada homem ficou com " << final_A << ", " << final_B << " e " << final_C << " reais, respectivamente\n";
        
        if (investment == 2) {
            char c1, c2, c3;
            std::cin >> c1 >> c2 >> c3;
            int sum = (c1 - 'a' + 1) + (c2 - 'a' + 1) + (c3 - 'a' + 1);
            std::cout << sum << "\n";
        } else if (investment == 3) {
            int age1, age2, age3;
            std::cin >> age1 >> age2 >> age3;
            if (age1 % 3 == 0 || age2 % 3 == 0 || age3 % 3 == 0) {
                int parcels = (age1 / 3) + (age2 / 3) + (age3 / 3);
                std::cout << parcels << "\n";
            }
        }
    } else {
        std::cout << "Nao foi dessa vez que Rebeka pode ajudar...\n";
    }

    if (rebekas_money >= 7) {
        std::cout << "Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n";
    } else {
        std::cout << "E parece que Rebeka vai ter que voltar andando...\n";
    }

    return 0;
}

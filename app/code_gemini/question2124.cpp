/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int solve(int n, long long fn_minus_2, long long fn_minus_1, long long P) {
    int blood_lost = (n + 1) * 12;

    if (blood_lost > 300) {
        return -1;
    }

    long long current_force = 2 * fn_minus_1 + fn_minus_2;

    if (current_force >= P) {
        return blood_lost;
    } else {
        return solve(n + 1, fn_minus_1, current_force, P);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long C, T, P;
    std::cin >> C >> T;
    std::cin >> P;

    if (C >= P) {
        std::cout << "Eleven perdeu 12ml de sangue.\n";
        return 0;
    }

    if (T >= P) {
        std::cout << "Eleven perdeu 24ml de sangue.\n";
        return 0;
    }

    int result = solve(2, C, T, P);

    if (result == -1) {
        std::cout << "Eleven ficou fraca demais e acabou desmaiando\n";
    } else {
        std::cout << "Eleven perdeu " << result << "ml de sangue.\n";
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

std::vector<double> memo(24, -1.0);

double calculate_chance(int h, double blood) {
    if (memo[h] != -1.0) {
        return memo[h];
    }

    if (h == 5) {
        memo[h] = 5.0;
        return 5.0;
    }

    int prev_h = (h == 0) ? 23 : h - 1;
    double prev_chance = calculate_chance(prev_h, blood);

    double current_chance;

    // De 06am às 03pm (6 to 15)
    if (h >= 6 && h <= 15) {
        if (h % 2 == 0) {
            current_chance = prev_chance + blood / 2.0;
        } else {
            current_chance = prev_chance + ((long long)prev_chance % 7);
        }
    }
    // De 04pm às 04am (16 to 23 and 0 to 4)
    else {
        if (h % 2 == 0) {
            current_chance = prev_chance + blood;
        } else {
            current_chance = prev_chance + ((long long)prev_chance % 10);
        }
    }
    
    memo[h] = current_chance;
    return current_chance;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h_input;
    std::string ampm;
    double blood_input;

    std::cin >> h_input >> ampm >> blood_input;

    if (blood_input < 0 || h_input < 1 || h_input > 12) {
        std::cout << "Dados Invalidos." << std::endl;
        return 0;
    }

    int target_h_24;
    if (ampm == "am") {
        if (h_input == 12) { 
            target_h_24 = 0;
        } else {
            target_h_24 = h_input;
        }
    } else { // ampm == "pm"
        if (h_input == 12) { 
            target_h_24 = 12;
        } else {
            target_h_24 = h_input + 12;
        }
    }

    double result = calculate_chance(target_h_24, blood_input);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "A chance de aparecimento de Demogorgon e de " << result << "%." << std::endl;

    if (result >= 100.0) {
        std::cout << "Ou seja, nao olhe para tras." << std::endl;
    }

    return 0;
}

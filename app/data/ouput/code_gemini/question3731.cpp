/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <vector>

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

int find_next_prime(int n) {
    int p = n + 1;
    while (true) {
        if (is_prime(p)) {
            return p;
        }
        p++;
    }
}

int sum_of_digits(int n) {
    int sum = 0;
    int temp = n;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return sum == 0 ? 1 : sum;
}

int sum_multiples_of_6(int n) {
    int sum = 0;
    for (int i = 6; i < n; i += 6) {
        sum += i;
    }
    return sum;
}

void MudancaDeLivros(int *codigo, int *posicao) {
    int old_code = *codigo;
    int old_pos = *posicao;

    int next_prime = find_next_prime(old_code);
    int digit_sum = sum_of_digits(old_code);
    *codigo = (old_code + next_prime) / digit_sum;

    int multiples_sum = sum_multiples_of_6(old_code);
    *posicao = std::abs(multiples_sum - old_pos);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> original_codes;
    std::vector<int> original_positions;
    
    int m, n;
    while (std::cin >> m >> n && m != 0) {
        original_codes.push_back(m);
        original_positions.push_back(n);
    }

    int count = original_codes.size();
    std::vector<int> new_codes(count);
    std::vector<int> new_positions(count);

    for (int i = 0; i < count; ++i) {
        int current_code = original_codes[i];
        int current_pos = original_positions[i];

        MudancaDeLivros(&current_code, &current_pos);

        while (true) {
            bool collision_found = false;
            for (int j = 0; j < i; ++j) {
                if (current_code == new_codes[j]) {
                    current_code++;
                    collision_found = true;
                    break;
                }
                if (current_pos == new_positions[j]) {
                    current_pos++;
                    collision_found = true;
                    break;
                }
            }
            if (!collision_found) {
                break;
            }
        }
        
        new_codes[i] = current_code;
        new_positions[i] = current_pos;
    }

    for (int i = count - 1; i >= 0; --i) {
        std::cout << new_codes[i] << " - " << new_positions[i] << std::endl;
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int check_validity(const int matrix[3][3]) {
    const int main_diag[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    const int sec_diag[3][3] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}};

    bool is_main = true;
    bool is_sec = true;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][j] != main_diag[i][j]) {
                is_main = false;
            }
            if (matrix[i][j] != sec_diag[i][j]) {
                is_sec = false;
            }
        }
    }

    if (is_main) return 1;
    if (is_sec) return 2;
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int luke_hp, vader_hp;
    std::cin >> luke_hp >> vader_hp;

    int luke_matrix[3][3];
    int vader_matrix[3][3];

    while (std::cin >> luke_matrix[0][0]) {
        std::cin >> luke_matrix[0][1] >> luke_matrix[0][2];
        for (int i = 1; i < 3; ++i) {
            std::cin >> luke_matrix[i][0] >> luke_matrix[i][1] >> luke_matrix[i][2];
        }

        for (int i = 0; i < 3; ++i) {
            std::cin >> vader_matrix[i][0] >> vader_matrix[i][1] >> vader_matrix[i][2];
        }
        
        int luke_attack = check_validity(luke_matrix);
        int vader_attack = check_validity(vader_matrix);

        if (luke_attack > 0 && vader_attack == 0) {
            vader_hp -= 15;
        } else if (luke_attack == 0 && vader_attack > 0) {
            luke_hp -= 15;
        } else if (luke_attack > 0 && vader_attack > 0) {
            if (luke_attack == vader_attack) {
                luke_hp -= 15;
                vader_hp -= 15;
            }
        }
    }

    if (luke_hp > vader_hp) {
        std::cout << "Luke Skywalker venceu.\n";
    } else if (vader_hp > luke_hp) {
        std::cout << "Darth Vader venceu.\n";
    } else {
        std::cout << "Houve empate.\n";
    }

    return 0;
}

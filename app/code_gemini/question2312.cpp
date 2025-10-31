/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

char board[8][8];
int captured_count = 0;
bool sopro_flag = false;
int player_r, player_c;

void find_player() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == '#') {
                player_r = i;
                player_c = j;
                return;
            }
        }
    }
}

void print_board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << board[i][j] << (j == 7 ? "" : " ");
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cin >> board[i][j];
        }
    }

    int n;
    std::cin >> n;

    for (int k = 0; k < n; ++k) {
        find_player();

        bool can_capture_e = false;
        int sopro_r_e = -1, sopro_c_e = -1;
        if (player_r >= 2 && player_c >= 2 &&
            board[player_r - 1][player_c - 1] == '%' &&
            board[player_r - 2][player_c - 2] == '*') {
            can_capture_e = true;
            sopro_r_e = player_r - 1;
            sopro_c_e = player_c - 1;
        }

        bool can_capture_d = false;
        int sopro_r_d = -1, sopro_c_d = -1;
        if (player_r >= 2 && player_c <= 5 &&
            board[player_r - 1][player_c + 1] == '%' &&
            board[player_r - 2][player_c + 2] == '*') {
            can_capture_d = true;
            sopro_r_d = player_r - 1;
            sopro_c_d = player_c + 1;
        }

        char move;
        std::cin >> move;

        if (move == 'E') {
            int target_r = player_r - 1;
            int target_c = player_c - 1;

            if (board[target_r][target_c] == '%') {
                int land_r = player_r - 2;
                int land_c = player_c - 2;

                if (board[land_r][land_c] == '%') {
                    std::cout << "Voce nao pode capturar essa peca.\n";
                } else {
                    std::cout << "Voce capturou uma peca na casa (" << target_r << "," << target_c
                              << ") e avancou para a casa (" << land_r << "," << land_c << ").\n";
                    board[player_r][player_c] = '*';
                    board[target_r][target_c] = '*';
                    board[land_r][land_c] = '#';
                    captured_count++;
                }
            } else {
                std::cout << "Voce avancou para a casa (" << target_r << "," << target_c << ").\n";
                board[player_r][player_c] = '*';
                board[target_r][target_c] = '#';

                if (can_capture_e || can_capture_d) {
                    sopro_flag = true;
                    if (can_capture_e) {
                        std::cout << "Voce deveria ter capturado a peca na casa (" << sopro_r_e << "," << sopro_c_e << ").\n";
                    } else {
                        std::cout << "Voce deveria ter capturado a peca na casa (" << sopro_r_d << "," << sopro_c_d << ").\n";
                    }
                }
            }
        } else if (move == 'D') {
            int target_r = player_r - 1;
            int target_c = player_c + 1;
            
            if (board[target_r][target_c] == '%') {
                int land_r = player_r - 2;
                int land_c = player_c + 2;

                if (board[land_r][land_c] == '%') {
                    std::cout << "Voce nao pode capturar essa peca.\n";
                } else {
                    std::cout << "Voce capturou uma peca na casa (" << target_r << "," << target_c
                              << ") e avancou para a casa (" << land_r << "," << land_c << ").\n";
                    board[player_r][player_c] = '*';
                    board[target_r][target_c] = '*';
                    board[land_r][land_c] = '#';
                    captured_count++;
                }
            } else {
                std::cout << "Voce avancou para a casa (" << target_r << "," << target_c << ").\n";
                board[player_r][player_c] = '*';
                board[target_r][target_c] = '#';

                if (can_capture_e || can_capture_d) {
                    sopro_flag = true;
                    if (can_capture_e) {
                        std::cout << "Voce deveria ter capturado a peca na casa (" << sopro_r_e << "," << sopro_c_e << ").\n";
                    } else {
                        std::cout << "Voce deveria ter capturado a peca na casa (" << sopro_r_d << "," << sopro_c_d << ").\n";
                    }
                }
            }
        }
    }

    print_board();
    std::cout << "Voce capturou " << captured_count << " pecas.\n";
    if (sopro_flag) {
        std::cout << "Deu sopro.\n";
    }

    return 0;
}

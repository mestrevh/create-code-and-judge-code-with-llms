/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> farm(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> farm[i][j];
        }
    }

    long long total_harvested = 0;
    long long total_insecticide = 0;

    std::string command;
    while (std::cin >> command) {
        if (command == "Plantar") {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string line;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            int row_index;
            while (ss >> row_index) {
                if (row_index >= 0 && row_index < N) {
                    bool is_empty = true;
                    for (int cell : farm[row_index]) {
                        if (cell != 0) {
                            is_empty = false;
                            break;
                        }
                    }
                    if (is_empty) {
                        for (int &cell : farm[row_index]) {
                            cell = 1;
                        }
                        total_insecticide += (long long)M * 2;
                    }
                }
            }
        } else if (command == "Temporada") {
            std::vector<std::vector<int>> temp_farm = farm;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (farm[i][j] == 1) {
                        temp_farm[i][j] = 2;
                        total_insecticide += 2;
                    } else if (farm[i][j] == 2) {
                        temp_farm[i][j] = 3;
                    }
                }
            }
            farm = temp_farm;
        } else if (command == "Colher") {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (farm[i][j] == 3) {
                        total_harvested++;
                        farm[i][j] = 0;
                    } else if (farm[i][j] == -1) {
                        farm[i][j] = 0;
                    }
                }
            }
        } else if (command == "Ataque") {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string line;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            int r, c;
            ss >> r >> c;
            if (r >= 0 && r < N && c >= 0 && c < M) {
                farm[r][c] = -1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << farm[i][j] << (j == M - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    std::cout << "Foram colhidos " << total_harvested << " morangos.\n";
    std::cout << "Foram utilizados " << total_insecticide << "ml de inseticida.\n";

    return 0;
}

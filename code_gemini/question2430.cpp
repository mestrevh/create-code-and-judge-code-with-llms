/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <utility>

void solve(int case_num) {
    int m;
    std::cin >> m;
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }

    std::vector<std::pair<std::string, double>> playlist(m);
    for (int i = 0; i < m; ++i) {
        std::getline(std::cin, playlist[i].first);
        std::cin >> playlist[i].second;
        if (std::cin.peek() == '\n') {
            std::cin.ignore();
        }
    }

    std::string commands;
    std::cin >> commands;

    double total_duration = 0.0;
    std::vector<std::string> played_songs;
    int current_index = 0;

    for (char cmd : commands) {
        if (cmd == 's') {
            break;
        }

        if (cmd == 'r') {
            if (current_index < m) {
                total_duration += playlist[current_index].second;
                played_songs.push_back(playlist[current_index].first);
                current_index++;
            }
        } else if (cmd == 'p') {
            if (current_index < m) {
                current_index++;
            }
        } else if (cmd == 'v') {
            if (current_index > 0) {
                total_duration += playlist[current_index - 1].second;
                played_songs.push_back(playlist[current_index - 1].first);
            }
        }
    }

    std::cout << "Viagem " << case_num << ": " << std::fixed << std::setprecision(15) << total_duration << std::endl;

    if (!played_songs.empty()) {
        for (size_t i = 0; i < played_songs.size(); ++i) {
            std::cout << played_songs[i] << (i == played_songs.size() - 1 ? "" : ", ");
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}

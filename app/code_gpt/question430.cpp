/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

void backtrack(int index, int limit, const std::vector<int>& songs, std::vector<int>& selected, std::vector<int>& best) {
    if (limit == 0) {
        if (selected.size() > best.size() || (selected.size() == best.size() && std::accumulate(selected.begin(), selected.end(), 0) > std::accumulate(best.begin(), best.end(), 0))) {
            best = selected;
        }
        return;
    }
    if (index >= songs.size() || limit < 0) return;

    backtrack(index + 1, limit, songs, selected, best);
    selected.push_back(songs[index]);
    backtrack(index + 1, limit - songs[index], songs, selected, best);
    selected.pop_back();
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int N, M;
        iss >> N >> M;
        std::vector<int> songs(M);
        for (int i = 0; i < M; ++i) {
            iss >> songs[i];
        }

        std::vector<int> selected, best;
        backtrack(0, N, songs, selected, best);

        if (!best.empty()) {
            for (int i = 0; i < best.size(); ++i) {
                std::cout << best[i] << (i < best.size() - 1 ? " " : "");
            }
            std::cout << " sum:" << std::accumulate(best.begin(), best.end(), 0) << std::endl;
        }
    }
    return 0;
}

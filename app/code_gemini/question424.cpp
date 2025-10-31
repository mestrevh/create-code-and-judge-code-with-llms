/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    int regular_players_count = 0;
    for (int i = 0; i < n; ++i) {
        bool scored_in_all = true;
        for (int j = 0; j < m; ++j) {
            int goals;
            std::cin >> goals;
            if (goals == 0) {
                scored_in_all = false;
            }
        }
        if (scored_in_all) {
            regular_players_count++;
        }
    }
    std::cout << regular_players_count << std::endl;
    return 0;
}

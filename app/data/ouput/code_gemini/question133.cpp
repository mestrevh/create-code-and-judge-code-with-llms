/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::map<std::pair<int, int>, int> requests;
        for (int i = 0; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            requests[{u, v}]++;
        }

        bool possible = true;
        for (auto it = requests.begin(); it != requests.end(); ++it) {
            int u = it->first.first;
            int v = it->first.second;

            auto reverse_it = requests.find({v, u});
            
            if (reverse_it == requests.end()) {
                possible = false;
                break;
            }
            
            if (it->second != reverse_it->second) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}

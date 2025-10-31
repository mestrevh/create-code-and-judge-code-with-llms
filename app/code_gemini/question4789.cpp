/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int p;
    std::cin >> p;
    for (int i = 0; i < p; ++i) {
        std::list<std::vector<int>> columns;
        std::string s_str;
        int c;

        while (std::cin >> s_str && s_str != "END") {
            int s = std::stoi(s_str);
            std::cin >> c;

            int n = columns.size();

            if (s == 0) {
                columns.push_front({c});
            } else if (s == n + 1) {
                columns.push_back({c});
            } else {
                auto it = columns.begin();
                std::advance(it, s - 1);

                if (!it->empty() && it->back() == c) {
                    while (!it->empty() && it->back() == c) {
                        it->pop_back();
                    }
                    if (it->empty()) {
                        columns.erase(it);
                    }
                } else {
                    it->push_back(c);
                }
            }
        }

        std::cout << "caso " << i << ":";
        if (!columns.empty()) {
            std::cout << " ";
            bool first = true;
            for (const auto& col : columns) {
                if (!first) {
                    std::cout << " ";
                }
                std::cout << col.back();
                first = false;
            }
        }
        std::cout << "\n";
    }

    return 0;
}

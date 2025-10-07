/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

enum Type { QUEUE, STACK };

struct Structure {
    Type type;
    std::deque<int> data;

    Structure(Type t = QUEUE) : type(t) {}

    bool is_empty() const {
        return data.empty();
    }

    int get_top_front() const {
        return data.front();
    }

    void insert(int val) {
        if (type == QUEUE) {
            data.push_back(val);
        } else {
            data.push_front(val);
        }
    }

    void remove() {
        if (!is_empty()) {
            data.pop_front();
        }
    }

    void transform() {
        type = (type == QUEUE) ? STACK : QUEUE;
    }
};

void solve() {
    int case_num = 0;
    std::string command;

    while (std::cin >> command) {
        std::vector<Structure> structures;
        structures.emplace_back(QUEUE);

        while (command != "END") {
            if (command == "ADD") {
                int i, v;
                std::cin >> i >> v;
                structures[i].insert(v);
            } else if (command == "DEL") {
                int i;
                std::cin >> i;
                structures[i].remove();
            } else if (command == "TRA") {
                int i;
                std::cin >> i;
                structures[i].transform();
            } else if (command == "SPL") {
                int i;
                std::cin >> i;
                
                Structure& original = structures[i];
                int n = original.data.size();
                int n1 = n / 2;

                Structure s1(original.type);
                Structure s2(original.type);

                s1.data.assign(original.data.begin(), original.data.begin() + n1);
                s2.data.assign(original.data.begin() + n1, original.data.end());

                structures[i] = s1;
                structures.insert(structures.begin() + i + 1, s2);
                
            } else if (command == "MER") {
                int i, j;
                std::cin >> i >> j;
                structures[i].data.insert(structures[i].data.end(), structures[j].data.begin(), structures[j].data.end());
                structures.erase(structures.begin() + j);
            }
            std::cin >> command;
        }

        std::cout << "caso " << case_num++ << ":";
        for (const auto& s : structures) {
            std::cout << " ";
            if (s.is_empty()) {
                std::cout << "?";
            } else {
                std::cout << s.get_top_front();
            }
        }
        std::cout << "\n\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

std::string a, b;
bool found_solution = false;

void print_path(const std::vector<int>& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << (i == path.size() - 1 ? "" : " ");
    }
    std::cout << "\n";
}

void find_sequences(int index_a, int index_b, std::vector<int>& path) {
    if (index_b == b.length()) {
        found_solution = true;
        print_path(path);
        return;
    }

    if (index_a == a.length()) {
        return;
    }

    for (int i = index_a; i < a.length(); ++i) {
        if ((a.length() - i) < (b.length() - index_b)) {
            break;
        }

        if (a[i] == b[index_b]) {
            path.push_back(i + 1);
            find_sequences(i + 1, index_b + 1, path);
            path.pop_back();
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::getline(std::cin, a);
    std::getline(std::cin, b);

    std::vector<int> current_path;
    find_sequences(0, 0, current_path);

    if (!found_solution) {
        std::cout << "-1\n";
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> path;
bool success_found = false;

void solve();

void print_full_path() {
    if (path.empty()) return;
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;
}

void print_failure_path() {
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << " -> ";
    }
    std::cout << "Fracasso" << std::endl;
}

void solve() {
    if (success_found || std::cin.peek() == EOF) {
        return;
    }

    std::string line;
    std::getline(std::cin, line);

    if (line.empty()) {
        return;
    }

    if (line == "Sucesso") {
        path.push_back(line);
        print_full_path();
        success_found = true;
        return;
    }
    
    if (line == "Fracasso") {
        print_failure_path();
        return;
    }

    path.push_back(line);

    solve();
    if (success_found) {
        return;
    }

    solve();
    if (success_found) {
        return;
    }

    if (!path.empty()) {
        path.pop_back();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (!success_found && std::cin.peek() != EOF) {
        solve();
    }

    return 0;
}

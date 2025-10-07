/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<std::string, std::string>> students;
    students.reserve(n);

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::cin >> line;

        size_t delimiter_pos = line.find('-');
        std::string id = line.substr(0, delimiter_pos);
        std::string name = line.substr(delimiter_pos + 1);

        students.push_back({name, id});
    }

    std::sort(students.begin(), students.end());

    std::cout << "Matricula: " << students[k - 1].second << std::endl;
    std::cout << "Nome: " << students[k - 1].first << std::endl;

    return 0;
}

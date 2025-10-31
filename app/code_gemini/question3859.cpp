/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n1, n2;
    std::cin >> n1 >> n2;

    std::unordered_set<long long> checklist;
    for (int i = 0; i < n1; ++i) {
        long long id;
        std::cin >> id;
        checklist.insert(id);
    }

    std::vector<long long> assembly_line;
    int new_elements_count = 0;
    long long current_id;

    while (new_elements_count < n2 && std::cin >> current_id) {
        assembly_line.push_back(current_id);
        if (checklist.find(current_id) == checklist.end()) {
            new_elements_count++;
        }
    }

    std::vector<long long> processed_values;
    size_t k = assembly_line.size();

    if (k > 0) {
        processed_values.resize(k);
        processed_values[0] = assembly_line[0];

        for (size_t i = 1; i < k - 1; ++i) {
            processed_values[i] = std::abs(assembly_line[i] * assembly_line[i - 1] - assembly_line[i + 1]);
        }

        if (k > 1) {
            processed_values[k - 1] = assembly_line[k - 1] * assembly_line[k - 2];
        }
    }
    
    std::sort(processed_values.begin(), processed_values.end());

    for (size_t i = 0; i < processed_values.size(); ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        if (checklist.count(processed_values[i])) {
            std::cout << "DELETADO";
        } else {
            std::cout << processed_values[i];
        }
    }
    std::cout << "\n";

    return 0;
}

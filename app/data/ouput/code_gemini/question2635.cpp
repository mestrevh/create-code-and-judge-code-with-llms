/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

struct Hostage {
    std::string name;
    long long number;
};

Hostage find_max_hostage(const std::vector<Hostage>& hostages, int start, int end) {
    if (start == end) {
        return hostages[start];
    }

    int mid = start + (end - start) / 2;
    Hostage left_max = find_max_hostage(hostages, start, mid);
    Hostage right_max = find_max_hostage(hostages, mid + 1, end);

    if (left_max.number > right_max.number) {
        return left_max;
    } else {
        return right_max;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<Hostage> hostages(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> hostages[i].name >> hostages[i].number;
    }

    Hostage max_hostage = find_max_hostage(hostages, 0, n - 1);

    if (max_hostage.name == "Alison") {
        std::cout << "Ela nao tentou bancar a espertinha de novo!\n";
    } else {
        std::cout << "ELA ROUBOU DE NOVO! TODOS ATRAS DE ALISON! O maior numero na parede e " << max_hostage.number << "!\n";
    }

    return 0;
}

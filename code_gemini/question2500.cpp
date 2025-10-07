/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

struct Dinosaur {
    int size;
    std::string name;
};

bool compareDinosaurs(const Dinosaur& a, const Dinosaur& b) {
    return a.name < b.name;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int capacity = 1;
    int count = 0;
    Dinosaur* dinosaurs = new Dinosaur[capacity];

    int n;
    std::string s;

    while (std::cin >> n >> s) {
        if (count == capacity) {
            int new_capacity = capacity * 2;
            Dinosaur* new_dinosaurs = new Dinosaur[new_capacity];
            for (int i = 0; i < count; ++i) {
                new_dinosaurs[i] = dinosaurs[i];
            }
            delete[] dinosaurs;
            dinosaurs = new_dinosaurs;
            capacity = new_capacity;
        }

        dinosaurs[count].size = n;
        dinosaurs[count].name = s;
        count++;
    }

    std::sort(dinosaurs, dinosaurs + count, compareDinosaurs);

    std::cout << "[";
    bool first_print = true;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < dinosaurs[i].size; ++j) {
            if (!first_print) {
                std::cout << ", ";
            }
            std::cout << dinosaurs[i].name;
            first_print = false;
        }
    }
    std::cout << "]\n";

    delete[] dinosaurs;

    return 0;
}

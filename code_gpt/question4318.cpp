/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct Child {
    std::string name;
    int age;
    double height;
    double score;

    Child(std::string n, int a, double h) : name(n), age(a), height(h) {
        score = height * age * n.length();
    }
};

bool compare(const Child& a, const Child& b, double x) {
    return std::fabs(a.score - x) < std::fabs(b.score - x);
}

int main() {
    int n, m;
    double x;
    std::cin >> n >> m >> x;
    std::vector<Child> children;

    for (int i = 0; i < n; ++i) {
        std::string name;
        int age;
        double height;
        std::cin >> name >> age >> height;
        children.emplace_back(name, age, height);
    }

    std::sort(children.begin(), children.end(), [&](const Child& a, const Child& b) {
        return compare(a, b, x);
    });

    for (int i = 0; i < m; ++i) {
        std::cout << children[i].name << std::endl;
    }

    return 0;
}

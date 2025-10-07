/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int identifier;
};

bool compare(const Person &a, const Person &b) {
    return a.identifier % 2 == 0 && b.identifier % 2 != 0;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Person> people(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> people[i].name >> people[i].identifier;
    }

    std::sort(people.begin(), people.end(), compare);

    for (const auto &p : people) {
        std::cout << p.name << std::endl;
    }

    return 0;
}

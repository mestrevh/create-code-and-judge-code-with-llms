/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int food_amount;
};

void serve_recursive(std::vector<Person>& people, int index) {
    if (index >= people.size()) {
        return;
    }

    serve_recursive(people, index + 1);

    while (people[index].food_amount > 0) {
        std::cout << people[index].name << " foi servido(a).\n";
        people[index].food_amount -= 400;
        if (people[index].food_amount > 0) {
            std::cout << "Fica tranquilo(a), " << people[index].name << " pode se servir novamente!\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Person> people(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> people[i].name >> people[i].food_amount;
    }

    serve_recursive(people, 0);

    return 0;
}

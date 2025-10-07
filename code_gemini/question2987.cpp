/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int id;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Person> people;
    std::string name;
    int id;

    while (std::cin >> name >> id) {
        people.push_back({name, id});
    }

    while (!people.empty()) {
        Person current_person = people[0];
        bool match_found = false;

        for (size_t i = 1; i < people.size(); ++i) {
            if (people[i].id == current_person.id) {
                std::cout << current_person.name << " seu parceiro esta na posicao " << i
                          << " e o seu nome e " << people[i].name << ".\n";

                people.erase(people.begin() + i);
                people.erase(people.begin());

                match_found = true;
                break;
            }
        }

        if (!match_found) {
            std::cout << current_person.name << " nao existe um parceiro para voce.\n";
            people.erase(people.begin());
        }
    }

    return 0;
}

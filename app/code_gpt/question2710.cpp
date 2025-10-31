/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
using namespace std;

struct Person {
    string name;
    int arrival;
    int duration;
    double successProbability;
};

class LinkedList {
    list<Person> people;
public:
    void addPerson(const string& name, int arrival, int duration, double successProbability) {
        people.push_back({name, arrival, duration, successProbability});
    }

    void printBestMatch(int currentHour) {
        string bestMatch = "";
        double maxProbability = -1;

        for (const auto& person : people) {
            if (person.arrival <= currentHour && currentHour < person.arrival + person.duration) {
                if (person.successProbability > maxProbability) {
                    maxProbability = person.successProbability;
                    bestMatch = person.name;
                }
            }
        }

        if (bestMatch.empty()) {
            cout << "Não tem ninguém para Frank agora" << endl;
        } else {
            cout << "A melhor match para Frank é " << bestMatch << endl;
        }
    }
};

int main() {
    int H;
    cin >> H;
    LinkedList guests;

    string name;
    int arrival, duration;
    double successProbability;

    while (cin >> name >> arrival >> duration >> successProbability) {
        guests.addPerson(name, arrival, duration, successProbability);
    }

    for (int hour = 0; hour < H; hour++) {
        guests.printBestMatch(hour);
    }

    return 0;
}

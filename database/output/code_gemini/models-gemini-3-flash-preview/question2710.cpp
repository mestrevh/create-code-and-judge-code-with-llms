/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    int arrival;
    int end;
    double percentage;
};

struct Node {
    Person person;
    Node* next;
    Node(const Person& p) : person(p), next(nullptr) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H;
    if (!(cin >> H)) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;

    string name;
    int arr, dur;
    double perc;

    while (cin >> name >> arr >> dur >> perc) {
        Person p;
        p.name = name;
        p.arrival = arr;
        p.end = arr + dur - 1;
        p.percentage = perc;

        Node* newNode = new Node(p);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    for (int h = 1; h <= H; ++h) {
        Node* current = head;
        string bestName = "";
        double maxP = -1.0;

        while (current) {
            if (h >= current->person.arrival && h <= current->person.end) {
                if (current->person.percentage > maxP) {
                    maxP = current->person.percentage;
                    bestName = current->person.name;
                }
            }
            current = current->next;
        }

        if (bestName.empty()) {
            cout << "Não tem ninguém para Frank agora\n";
        } else {
            cout << "A melhor match para Frank é " << bestName << "\n";
        }
    }

    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
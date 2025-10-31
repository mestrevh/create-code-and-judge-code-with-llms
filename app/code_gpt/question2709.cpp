/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

struct Node {
    std::string name;
    double grade;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void add(const std::string& name, double grade) {
        Node* newNode = new Node{name, grade, head};
        head = newNode;
    }

    void process(double& currentGrade, double goalGrade) {
        double totalIncrease = 0;
        std::vector<std::string> notNeeded;

        Node* temp = head;
        while (temp != nullptr) {
            double limitGrade = 0.5 * currentGrade + 0.5;

            if (temp->grade < limitGrade) {
                notNeeded.push_back(temp->name);
                temp = temp->next;
                continue;
            }

            double increase = 0.1 * (temp->grade - currentGrade);
            currentGrade += increase;
            totalIncrease += increase;

            std::cout << "Minha nota aumentou em " << std::fixed << std::setprecision(4) 
                      << increase << " por causa de " << temp->name << "!" << std::endl;

            if (currentGrade >= goalGrade) {
                std::cout << "Consegui a nota sonhada, ja posso comprar a casa dos meus sonhos, nao preciso de mais ninguem." << std::endl;
                break;
            }

            std::cout << "Ja consegui aumentar " << std::fixed << std::setprecision(4) 
                      << totalIncrease << " na minha nota" << std::endl;
            std::cout << "Atualmente estou com " << std::fixed << std::setprecision(4) 
                      << currentGrade << " e ainda falta " << std::fixed << std::setprecision(4) 
                      << (goalGrade - currentGrade) << " para conseguir a nota sonhada." << std::endl;

            temp = temp->next;
        }

        if (currentGrade < goalGrade) {
            if (!notNeeded.empty()) {
                std::cout << "Pessoas que nao preciso cativar:" << std::endl;
                for (const auto& name : notNeeded) {
                    std::cout << name << std::endl;
                }
            } else {
                std::cout << "Mesmo com tantos amigos nao consegui minha casa dos sonhos :(" << std::endl;
            }
        }
    }
};

int main() {
    double initialGrade;
    std::cin >> initialGrade;

    LinkedList peopleList;
    std::string name;
    double grade;

    while (std::cin >> name >> grade) {
        peopleList.add(name, grade);
    }

    peopleList.process(initialGrade, 4.5);

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

struct Node {
    std::string studentName;
    Node* next;
};

void insert(Node*& head, const std::string& name) {
    Node* newNode = new Node;
    newNode->studentName = name;
    newNode->next = head;
    head = newNode;
}

void remove(Node*& head, const std::string& name) {
    if (head == nullptr) {
        return;
    }

    if (head->studentName == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->studentName != name) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

int count(Node* head) {
    int c = 0;
    Node* current = head;
    while (current != nullptr) {
        c++;
        current = current->next;
    }
    return c;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> courseNames = {"Algoritmo", "SD", "Fisica", "Logica", "Estatistica"};
    std::map<std::string, int> courseMap;
    for (int i = 0; i < courseNames.size(); ++i) {
        courseMap[courseNames[i]] = i;
    }

    std::vector<Node*> heads(courseNames.size(), nullptr);
    std::string line;

    while (getline(std::cin, line) && !line.empty()) {
        std::stringstream ss(line);
        std::string course, name;
        ss >> course >> name;
        if (courseMap.count(course)) {
            int index = courseMap[course];
            insert(heads[index], name);
        }
    }

    while (getline(std::cin, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string course, name;
        ss >> course >> name;
        if (courseMap.count(course)) {
            int index = courseMap[course];
            remove(heads[index], name);
        }
    }

    for (size_t i = 0; i < courseNames.size(); ++i) {
        int studentCount = count(heads[i]);
        std::cout << "Estao matriculados na turma de " << courseNames[i]
                  << " " << studentCount << " aluno(os)\n";
    }
    
    for (size_t i = 0; i < heads.size(); ++i) {
        Node* current = heads[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct FriendNode {
    std::string name;
    int age;
    FriendNode* next;

    FriendNode(std::string n, int a) : name(n), age(a), next(nullptr) {}
};

void print_names(const std::vector<std::string>& names) {
    if (names.empty()) {
        std::cout << "Eleven nao tem amigos com essa idade." << std::endl;
    } else {
        bool first = true;
        for (const std::string& name : names) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << name;
            first = false;
        }
        std::cout << std::endl;
    }
}

void clear_list(FriendNode* head) {
    FriendNode* current = head;
    while (current != nullptr) {
        FriendNode* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;

    FriendNode* head = nullptr;
    FriendNode* tail = nullptr;

    for (int i = 0; i < q; ++i) {
        std::string name;
        int age;
        std::cin >> name >> age;
        FriendNode* newNode = new FriendNode(name, age);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int s;
    std::cin >> s;

    std::vector<std::string> found_names;
    FriendNode* current = head;
    while (current != nullptr) {
        if (current->age == s) {
            found_names.push_back(current->name);
        }
        current = current->next;
    }

    print_names(found_names);

    clear_list(head);

    return 0;
}

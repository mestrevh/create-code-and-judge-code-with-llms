/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct Friend {
    std::string name;
    int age;
    Friend* next;
};

class FriendList {
public:
    FriendList() : head(nullptr) {}

    void addFriend(const std::string& name, int age) {
        Friend* newFriend = new Friend{name, age, head};
        head = newFriend;
    }

    std::vector<std::string> findFriendsByAge(int age) {
        std::vector<std::string> names;
        Friend* current = head;
        while (current) {
            if (current->age == age) {
                names.push_back(current->name);
            }
            current = current->next;
        }
        return names;
    }

private:
    Friend* head;
};

int main() {
    int Q;
    std::cin >> Q;
    FriendList friends;
    
    for (int i = 0; i < Q; ++i) {
        std::string name;
        int age;
        std::cin >> name >> age;
        friends.addFriend(name, age);
    }
    
    int S;
    std::cin >> S;

    std::vector<std::string> result = friends.findFriendsByAge(S);
    if (result.empty()) {
        std::cout << "Eleven nao tem amigos com essa idade." << std::endl;
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i];
            if (i != result.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct FriendNode {
    string name;
    int age;
    FriendNode* next;

    FriendNode(string n, int a) : name(n), age(a), next(nullptr) {}
};

struct FriendList {
    FriendNode* head;
    FriendNode* tail;

    FriendList() : head(nullptr), tail(nullptr) {}

    void addFriend(const string& name, int age) {
        FriendNode* newNode = new FriendNode(name, age);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    ~FriendList() {
        FriendNode* current = head;
        while (current) {
            FriendNode* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;

    FriendList list;
    for (int i = 0; i < Q; ++i) {
        string name;
        int age;
        cin >> name >> age;
        list.addFriend(name, age);
    }

    int targetAge;
    if (!(cin >> targetAge)) return 0;

    bool found = false;
    bool first = true;
    FriendNode* current = list.head;

    while (current != nullptr) {
        if (current->age == targetAge) {
            if (!first) {
                cout << " ";
            }
            cout << current->name;
            found = true;
            first = false;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Eleven nao tem amigos com essa idade.";
    }
    cout << "\n";

    return 0;
}
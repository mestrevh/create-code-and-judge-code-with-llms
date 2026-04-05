/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string task;
    int count;
    Node* next;
    Node(const string& t) : task(t), count(1), next(nullptr) {}
};

class LinkedListTasks {
    Node* head;
public:
    LinkedListTasks() : head(nullptr) {}

    ~LinkedListTasks() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void add(const string& t) {
        if (!head) {
            head = new Node(t);
            return;
        }
        Node* cur = head;
        Node* prev = nullptr;
        while (cur && cur->task != t) {
            prev = cur;
            cur = cur->next;
        }
        if (!cur) {
            if (!prev) {
                head = new Node(t);
            } else {
                prev->next = new Node(t);
            }
        } else {
            cur->count++;
        }
    }

    bool finalize(const string& t) {
        Node* cur = head;
        Node* prev = nullptr;
        while (cur && cur->task != t) {
            prev = cur;
            cur = cur->next;
        }
        if (!cur) return false;

        cur->count--;
        if (cur->count == 0) {
            if (!prev) head = cur->next;
            else prev->next = cur->next;
            delete cur;
        }
        return true;
    }

    int findCount(const string& t) const {
        Node* cur = head;
        while (cur && cur->task != t) cur = cur->next;
        return cur ? cur->count : 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedListTasks lst;
    int C;

    while (cin >> C) {
        if (C == 0) break;
        string dummy;
        getline(cin, dummy);
        string task;
        getline(cin, task);

        if (C == 1) {
            lst.add(task);
            cout << "A tarefa " << task << " foi cadastrada com sucesso.\n";
        } else if (C == 2) {
            lst.finalize(task);
            cout << "A tarefa " << task << " foi finalizada e um Mr. Meeseeks se despede de nos.\n";
        } else if (C == 3) {
            int cnt = lst.findCount(task);
            if (cnt > 0) {
                cout << "Mr. Meeseeks: Eu sou o Mr. Meeseeks e estou fazendo a tarefa " << task << ". Olhe para mim!\n";
            } else {
                cout << "A tarefa " << task << " nao esta sendo atendida por nenhum Mr. Meeseeks.\n";
            }
        }
    }

    return 0;
}
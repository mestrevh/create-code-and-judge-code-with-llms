/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string type;
    Node* next;
    Node(const string& t) : type(t), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void push_back(const string& t) {
        Node* newNode = new Node(t);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool findAndRemove(const string& t) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            if (curr->type == t) {
                if (prev) {
                    prev->next = curr->next;
                    if (curr == tail) tail = prev;
                } else {
                    head = curr->next;
                    if (!head) tail = nullptr;
                }
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void printRemaining() {
        cout << "Flechas que sobraram:";
        Node* curr = head;
        while (curr) {
            cout << " " << curr->type;
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedList quiver;
    string line;

    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line == "Recarga feita") break;
        if (line.empty()) continue;
        quiver.push_back(line);
    }

    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line == "Fim da simulacao") break;
        if (line.empty()) continue;

        if (quiver.findAndRemove(line)) {
            cout << "Flecha disparada" << endl;
        } else {
            cout << "Flecha nao encontrada" << endl;
        }
    }

    quiver.printRemaining();

    return 0;
}
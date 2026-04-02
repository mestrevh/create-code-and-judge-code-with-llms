/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string title;
    Node* next;
    Node(string t) : title(t), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(string t) {
        Node* newNode = new Node(t);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    if (N <= 0) {
        cout << "Nao tem livros por aqui" << endl;
        return 0;
    }

    bool found = false;
    int foundShelf = -1;
    int foundPos = -1;

    for (int i = 1; i <= N; ++i) {
        int L;
        if (!(cin >> L)) break;

        LinkedList shelf;
        for (int j = 0; j < L; ++j) {
            string title;
            getline(cin >> ws, title);
            shelf.push_back(title);
        }

        if (!found) {
            Node* curr = shelf.head;
            int pos = 1;
            while (curr) {
                if (curr->title == "Livro de Rimas") {
                    found = true;
                    foundShelf = i;
                    foundPos = pos;
                    break;
                }
                curr = curr->next;
                pos++;
            }
        }
    }

    if (found) {
        cout << "Og Loc, o livro ta na estante " << foundShelf << ", na posicao " << foundPos << endl;
    } else {
        cout << "Og Loc, o livro nao esta aqui!" << endl;
    }

    return 0;
}
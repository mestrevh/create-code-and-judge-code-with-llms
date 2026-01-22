/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

struct Node {
    std::string data;
    Node* next;

    Node(const std::string& val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void insert_end(const std::string& val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int find(const std::string& target) {
        Node* current = head;
        int position = 1;
        while (current != nullptr) {
            if (current->data == target) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Nao tem livros por aqui" << std::endl;
        return 0;
    }

    bool found = false;
    int found_shelf = -1;
    int found_pos = -1;
    const std::string target_book = "Livro de Rimas";

    for (int i = 1; i <= n; ++i) {
        int l;
        std::cin >> l;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (found) {
            for (int j = 0; j < l; ++j) {
                std::string dummy;
                std::getline(std::cin, dummy);
            }
        } else {
            LinkedList current_shelf;
            for (int j = 0; j < l; ++j) {
                std::string book_title;
                std::getline(std::cin, book_title);
                current_shelf.insert_end(book_title);
            }
            
            int pos = current_shelf.find(target_book);
            if (pos != -1) {
                found = true;
                found_shelf = i;
                found_pos = pos;
            }
        }
    }

    if (found) {
        std::cout << "Og Loc, o livro ta na estante " << found_shelf << ", na posicao  " << found_pos << std::endl;
    } else {
        std::cout << "Og Loc, o livro nao esta aqui!" << std::endl;
    }

    return 0;
}

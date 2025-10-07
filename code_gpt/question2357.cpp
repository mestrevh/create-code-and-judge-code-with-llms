/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::string bookName;
    Node* next;
    Node(const std::string& name) : bookName(name), next(nullptr) {}
};

class Shelf {
public:
    Node* head;
    Shelf() : head(nullptr) {}
    void addBook(const std::string& name) {
        Node* newBook = new Node(name);
        newBook->next = head;
        head = newBook;
    }
    bool findBook(const std::string& name, int& position) {
        Node* current = head;
        position = 0;
        while (current) {
            if (current->bookName == name) {
                return true;
            }
            current = current->next;
            position++;
        }
        return false;
    }
};

int main() {
    int N;
    std::cin >> N;
    if (N == 0) {
        std::cout << "Nao tem livros por aqui" << std::endl;
        return 0;
    }

    std::vector<Shelf> shelves(N);
    for (int i = 0; i < N; i++) {
        int L;
        std::cin >> L;
        std::cin.ignore();
        for (int j = 0; j < L; j++) {
            std::string bookName;
            std::getline(std::cin, bookName);
            shelves[i].addBook(bookName);
        }
    }

    std::string searchBook = "Livro de Rimas";
    bool found = false;
    for (int i = 0; i < N && !found; i++) {
        int position;
        if (shelves[i].findBook(searchBook, position)) {
            std::cout << "Og Loc, o livro ta na estante " << (i + 1) << ", na posicao " << position << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Og Loc, o livro nao esta aqui!" << std::endl;
    }

    return 0;
}

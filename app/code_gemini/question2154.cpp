/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class HashTable {
private:
    int m;
    int total_elements;
    Node** table;

    int hash_function(int k) {
        return k % m;
    }

public:
    HashTable(int size) {
        m = size;
        total_elements = 0;
        table = new Node*[m];
        for (int i = 0; i < m; ++i) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < m; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(int k) {
        int index = hash_function(k);
        Node* newNode = new Node{k, nullptr};

        if (table[index] == nullptr || k < table[index]->data) {
            newNode->next = table[index];
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr && current->next->data < k) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        total_elements++;
    }

    void remove(int k) {
        int index = hash_function(k);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr && current->data != k) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        if (prev == nullptr) {
            table[index] = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        total_elements--;
    }

    void search(int k) {
        std::cout << "BUSCA POR " << k << std::endl;
        std::cout << "numero de elementos da tabela hash: " << total_elements << std::endl;

        int index = hash_function(k);
        Node* current = table[index];
        int accessed_count = 0;
        bool found = false;

        while (current != nullptr && current->data <= k) {
            accessed_count++;
            if (current->data == k) {
                found = true;
                break;
            }
            current = current->next;
        }

        if (found) {
            std::cout << "elemento " << k << " encontrado!" << std::endl;
            std::cout << "numero de elementos acessados na tabela hash: " << accessed_count << std::endl;
        } else {
            std::cout << "elemento nao encontrado!" << std::endl;
            std::cout << "numero de elementos acessados na tabela hash: 0" << std::endl;
        }
    }

    void print() {
        std::cout << "imprimindo tabela hash:" << std::endl;
        for (int i = 0; i < m; ++i) {
            std::cout << "[" << i << "]:";
            Node* current = table[i];
            if (current == nullptr) {
                std::cout << "Lista vazia!" << std::endl;
            } else {
                while (current != nullptr) {
                    std::cout << current->data << "=>";
                    current = current->next;
                }
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    if (!(std::cin >> m)) {
        return 0;
    }

    HashTable ht(m);

    char op;
    int k;
    while (std::cin >> op && op != 'f') {
        switch (op) {
            case 'a':
                std::cin >> k;
                ht.insert(k);
                break;
            case 'r':
                std::cin >> k;
                ht.remove(k);
                break;
            case 'i':
                ht.print();
                break;
            case 'p':
                std::cin >> k;
                ht.search(k);
                break;
        }
    }

    return 0;
}

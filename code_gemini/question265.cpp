/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

struct Node {
    char character;
    int frequency;
    Node* next;

    Node(char c, int f, Node* n) : character(c), frequency(f), next(n) {}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int freq[256] = {0};
    std::string line;
    std::getline(std::cin, line);

    for (char c : line) {
        freq[static_cast<unsigned char>(c)]++;
    }

    Node* head = nullptr;

    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            char currentChar = static_cast<char>(i);
            head = new Node(currentChar, freq[i], head);
        }
    }

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->character << " " << current->frequency << "\n";
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        Node* to_delete = current;
        current = current->next;
        delete to_delete;
    }

    return 0;
}

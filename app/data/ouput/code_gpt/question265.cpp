/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

struct Node {
    char character;
    int frequency;
    Node* next;
    Node(char c, int freq) : character(c), frequency(freq), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    
    void insert(char c, int freq) {
        Node* newNode = new Node(c, freq);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->character << " " << current->frequency << std::endl;
            current = current->next;
        }
    }
};

void createFrequencyList(const std::string& text) {
    std::unordered_map<char, int> freqMap;
    for (char c : text) {
        freqMap[c]++;
    }

    LinkedList list;
    for (const auto& pair : freqMap) {
        list.insert(pair.first, pair.second);
    }

    list.print();
}

int main() {
    std::string text = "hoje esta quente, logo esta umido.";
    createFrequencyList(text);
    return 0;
}

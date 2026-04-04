/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct Node {
    char character;
    int frequency;
    Node* next;
    Node(char c, int f, Node* n) : character(c), frequency(f), next(n) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int freq[256];
    for (int i = 0; i < 256; ++i) {
        freq[i] = 0;
    }

    char c;
    while (cin.get(c)) {
        if (c == '\n' || c == '\r') continue;
        freq[(unsigned char)c]++;
    }

    Node* head = nullptr;

    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            Node* newNode = new Node((char)i, freq[i], head);
            head = newNode;
        }
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->character << " " << current->frequency << "\n";
        current = current->next;
    }

    return 0;
}
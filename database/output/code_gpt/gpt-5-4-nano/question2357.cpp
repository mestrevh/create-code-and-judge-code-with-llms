/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string val;
    Node* next;
    Node(const string& v) : val(v), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    bool anyBook = false;
    int foundShelf = -1, foundPos = -1;

    for (int i = 1; i <= N; i++) {
        int L;
        cin >> L;

        Node* head = nullptr;
        Node* tail = nullptr;

        bool shelfFound = false;
        int pos = -1;

        for (int j = 0; j < L; j++) {
            string s;
            cin >> s;
            if (!head) {
                head = tail = new Node(s);
            } else {
                tail->next = new Node(s);
                tail = tail->next;
            }
            if (s == "Livro de Rimas") {
                shelfFound = true;
                pos = j;
            }
        }

        if (L > 0) anyBook = true;

        if (shelfFound && foundShelf == -1) {
            foundShelf = i;
            foundPos = pos;
        }

        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    if (!anyBook) {
        cout << "Nao tem livros por aqui";
    } else if (foundShelf != -1) {
        cout << "Og Loc, o livro ta na estante " << foundShelf << ", na posicao " << foundPos;
    } else {
        cout << "Og Loc, o livro nao esta aqui!";
    }

    return 0;
}
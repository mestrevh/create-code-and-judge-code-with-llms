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

    Node* head = nullptr;
    Node* tail = nullptr;

    vector<string> order;
    order.reserve(N);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> ws;
        getline(cin, s);
        if (head == nullptr) {
            head = tail = new Node(s);
        } else {
            tail->next = new Node(s);
            tail = tail->next;
        }
        order.push_back(s);
    }

    vector<Node*> nodes;
    nodes.reserve(N);
    Node* cur = head;
    while (cur) {
        nodes.push_back(cur);
        cur = cur->next;
    }

    string line;
    vector<string> queries;

    while (true) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;
        queries.push_back(line);
    }

    int K = (int)queries.size();
    for (int i = 0; i < K; i++) {
        string q = queries[i];
        int pos = -1;
        for (int j = 0; j < N; j++) {
            if (order[j] == q) {
                pos = j;
                break;
            }
        }

        if (pos == -1) {
            cout << q << " nao pode ser cursada nessa cadeia de pre-requisitos.\n";
        } else if (pos == 0) {
            cout << q << " podera ser cursada esse periodo.\n";
        } else {
            cout << q << " podera ser cursada depois de " << pos << " periodos, depois de ter passado por: ";
            for (int j = 0; j < pos; j++) {
                if (j) cout << " e ";
                cout << order[j];
            }
            cout << ".\n";
        }
    }

    cur = head;
    while (cur) {
        Node* nx = cur->next;
        delete cur;
        cur = nx;
    }
    return 0;
}
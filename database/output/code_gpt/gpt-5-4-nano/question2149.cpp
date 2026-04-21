/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string key;
    int count;
    Node* next;
    Node(const string& k, int c) : key(k), count(c), next(nullptr) {}
};

static Node* findNode(Node* head, const string& k) {
    Node* cur = head;
    while (cur) {
        if (cur->key == k) return cur;
        cur = cur->next;
    }
    return nullptr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> disciplinas = {"Algoritmo", "SD", "Fisica", "Logica", "Estatistica", "OBS"};

    Node* head = nullptr;
    Node* tail = nullptr;
    for (const auto& d : disciplinas) {
        Node* n = new Node(d, 0);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }

    auto parseLine = [&](const string& line, string& cadeira, string& nome) -> bool {
        if (line.empty()) return false;
        size_t pos = line.find(' ');
        if (pos == string::npos) return false;
        cadeira = line.substr(0, pos);
        size_t start = pos + 1;
        while (start < line.size() && line[start] == ' ') start++;
        if (start >= line.size()) return false;
        nome = line.substr(start);
        return true;
    };

    string line;
    bool second = false;
    map<string, unordered_set<string>> stage1;
    while (true) {
        if (!getline(cin, line)) break;
        if (line.size() == 0) { second = true; continue; }
        string cadeira, nome;
        if (!parseLine(line, cadeira, nome)) continue;

        if (!second) {
            stage1[cadeira].insert(nome);
        } else {
            auto it = stage1.find(cadeira);
            if (it != stage1.end()) it->second.erase(nome);
        }
    }

    for (const auto& d : disciplinas) {
        int cnt = 0;
        auto it = stage1.find(d);
        if (it != stage1.end()) cnt = (int)it->second.size();
        Node* n = findNode(head, d);
        if (n) n->count = cnt;
    }

    Node* cur = head;
    while (cur) {
        cout << "Estao matriculados na turma de " << cur->key << " " << cur->count << " aluno(os)\n";
        cur = cur->next;
    }

    return 0;
}
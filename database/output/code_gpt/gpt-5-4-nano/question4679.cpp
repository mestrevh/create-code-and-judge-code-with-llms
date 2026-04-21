/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Aluno {
    string nome;
    Aluno* next;
    Aluno(const string& n) : nome(n), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Aluno* head[4] = {nullptr, nullptr, nullptr, nullptr};
    Aluno* tail[4] = {nullptr, nullptr, nullptr, nullptr};

    string nome;
    while (true) {
        if (!getline(cin, nome)) break;
        if (nome.size() == 0 && cin.eof()) break;

        string line;
        if (!getline(cin, line)) break;
        while (line.size() == 0 && !cin.eof() && cin.peek() == '\n') {
            if (!getline(cin, line)) break;
        }

        int turma = 0;
        try {
            size_t idx = 0;
            turma = stoi(line, &idx);
        } catch (...) {
            continue;
        }
        if (turma < 1 || turma > 3) continue;

        Aluno* a = new Aluno(nome);
        if (!head[turma]) {
            head[turma] = tail[turma] = a;
        } else {
            tail[turma]->next = a;
            tail[turma] = a;
        }
    }

    for (int t = 1; t <= 3; t++) {
        cout << "Turma " << t << ":\n";
        Aluno* cur = head[t];
        while (cur) {
            cout << cur->nome << "\n";
            cur = cur->next;
        }
        if (t != 3) cout << "\n";
    }

    for (int t = 1; t <= 3; t++) {
        Aluno* cur = head[t];
        while (cur) {
            Aluno* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    return 0;
}
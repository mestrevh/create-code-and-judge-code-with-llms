/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Ap {
    int id;
    string gioia;
    string portador;
    int qenv;
    vector<string> env;
    Ap* next;
    Ap(int _id, const string& _gioia, const string& _portador, int _qenv, const vector<string>& _env)
        : id(_id), gioia(_gioia), portador(_portador), qenv(_qenv), env(_env), next(nullptr) {}
};

struct JoiaNode {
    string nome;
    Ap* apps;
    JoiaNode* next;
    JoiaNode(const string& n): nome(n), apps(nullptr), next(nullptr) {}
};

static const string JOIAS[6] = {"Mente","Realidade","Poder","Espaco","Tempo","Alma"};

struct DS {
    JoiaNode* head;
    DS(): head(nullptr) {}

    JoiaNode* findJoiaRec(JoiaNode* cur, const string& n) {
        if (!cur) return nullptr;
        if (cur->nome == n) return cur;
        return findJoiaRec(cur->next, n);
    }

    JoiaNode* getOrCreateJoiaRec(JoiaNode* cur, const string& n) {
        if (!cur) return nullptr;
        if (cur->nome == n) return cur;
        return getOrCreateJoiaRec(cur->next, n);
    }

    JoiaNode* ensureJoia(const string& n) {
        JoiaNode* j = findJoiaRec(head, n);
        if (j) return j;
        JoiaNode* nn = new JoiaNode(n);
        nn->next = head;
        head = nn;
        return nn;
    }

    Ap* findAppByIdRec(Ap* cur, int id) {
        if (!cur) return nullptr;
        if (cur->id == id) return cur;
        return findAppByIdRec(cur->next, id);
    }

    Ap* findLastRec(Ap* cur) {
        if (!cur) return nullptr;
        if (!cur->next) return cur;
        return findLastRec(cur->next);
    }

    void insertAppRec(Ap*& cur, Ap* node) {
        if (!cur) {
            cur = node;
            return;
        }
        if (node->id < cur->id) {
            node->next = cur;
            cur = node;
            return;
        }
        insertAppRec(cur->next, node);
    }

    int countAppsRec(Ap* cur) {
        if (!cur) return 0;
        return 1 + countAppsRec(cur->next);
    }

    Ap* lastAppRec(Ap* cur) {
        if (!cur) return nullptr;
        if (!cur->next) return cur;
        return lastAppRec(cur->next);
    }

    string portadorLastRec(Ap* cur) {
        Ap* a = lastAppRec(cur);
        return a ? a->portador : "";
    }

    bool hasAppRec(Ap* cur) {
        return cur != nullptr;
    }

    void removeAppByIdRec(Ap*& cur, int id, bool& removed) {
        if (!cur) return;
        if (cur->id == id) {
            Ap* del = cur;
            cur = cur->next;
            delete del;
            removed = true;
            return;
        }
        removeAppByIdRec(cur->next, id, removed);
    }

    void removeAppFromAllInvalidRec(JoiaNode* cur, int id, bool& removed) {
        if (!cur) return;
        if (removed) return;
        removeAppByIdRec(cur->apps, id, removed);
        removeAppFromAllInvalidRec(cur->next, id, removed);
    }

    void addInOrderByIdRec(Ap*& cur, Ap* node) {
        insertAppRec(cur, node);
    }

    void listAppsByCharacterRec(Ap* cur, const string& nome, bool& any, ostream& out) {
        if (!cur) return;
        bool involved = false;
        for (const string& s : cur->env) if (s == nome) { involved = true; break; }
        if (involved) {
            out << cur->id << " (" << cur->gioia << ").\n";
            any = true;
        }
        listAppsByCharacterRec(cur->next, nome, any, out);
    }

    void listAppsByCharacterAcrossJoiasRec(JoiaNode* cur, const string& nome, ostream& out, vector<pair<int,string>>& tmp) {
        if (!cur) return;
        listAppsForJoiaCollectRec(cur->apps, cur->nome, nome, out, tmp);
        listAppsByCharacterAcrossJoiasRec(cur->next, nome, out, tmp);
    }

    void listAppsForJoiaCollectRec(Ap* cur, const string& joiaNome, const string& nome, ostream& out, vector<pair<int,string>>& tmp) {
        if (!cur) return;
        bool involved = false;
        for (const string& s : cur->env) if (s == nome) { involved = true; break; }
        if (involved) tmp.push_back({cur->id, cur->gioia});
        listAppsForJoiaCollectRec(cur->next, joiaNome, nome, out, tmp);
    }

    static bool isValidJoia(const string& s) {
        for (int i = 0; i < 6; i++) if (JOIAS[i] == s) return true;
        return false;
    }

    static bool isValidCommand(const string& c) {
        return c == "REGISTRAR" || c == "PARADEIRO" || c == "PROCURAR" || c == "MENTIRA";
    }

    void handleRegistrar(int id, const string& gioia, const string& portador, int qenv, vector<string>& env, ostream& out) {
        JoiaNode* j = ensureJoia(gioia);
        Ap* node = new Ap(id, gioia, portador, qenv, env);
        addInOrderByIdRec(j->apps, node);
        int cnt = countAppsRec(j->apps);
        out << "Aparicao registrada com sucesso (" << cnt << ").\n";
    }

    void handleParadeiro(const string& gioia, ostream& out) {
        JoiaNode* j = findJoiaRec(head, gioia);
        if (!j || !hasAppRec(j->apps)) {
            out << "Ainda nao houve nenhuma aparicao da Joia do(a) " << gioia << ".\n";
            return;
        }
        Ap* last = lastAppRec(j->apps);
        out << "A ultima aparicao da Joia do(a) " << gioia << " foi a: " << last->id << ".\n";
        out << "Portador: " << last->portador << ".\n";
        if (last->qenv > 0) {
            out << "Personagens envolvidos: ";
            for (int i = 0; i < last->qenv; i++) {
                if (i) out << ", ";
                out << last->env[i];
            }
            out << ".\n";
        }
    }

    void handleProcurar(const string& nome, ostream& out) {
        vector<pair<int,string>> tmp;
        listAppsByCharacterAcrossJoiasRec(head, nome, out, tmp);
        if (tmp.empty()) {
            out << "Ainda nao houve nenhum envolvimento do personagem " << nome << " em aparicoes de Joias.\n";
            return;
        }
        sort(tmp.begin(), tmp.end(), [](auto& a, auto& b){ return a.first < b.first; });
        out << nome << " participou das aparicoes:\n";
        for (auto &p : tmp) out << p.first << " (" << p.second << ").\n";
    }

    void handleMentira(int id, ostream& out) {
        bool removed = false;
        removeAppFromAllInvalidRec(head, id, removed);
        out << "Aparicao removida com sucesso.\n";
    }
};

static inline string trimCR(const string& s) {
    if (!s.empty() && s.back() == '\r') return s.substr(0, s.size()-1);
    return s;
}

static bool readNonEmptyLine(string& line) {
    while (true) {
        if (!getline(cin, line)) return false;
        line = trimCR(line);
        if (line.size() == 0) continue;
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string dummy;
    getline(cin, dummy);

    DS ds;

    for (int i = 0; i < N; i++) {
        string cmd;
        if (!readNonEmptyLine(cmd)) break;

        if (cmd == "REGISTRAR") {
            string sID, gioia, portador, sQenv;
            readNonEmptyLine(sID);
            int id = stoi(sID);
            readNonEmptyLine(gioia);
            readNonEmptyLine(portador);
            readNonEmptyLine(sQenv);
            int qenv = stoi(sQenv);
            vector<string> env;
            env.reserve(qenv);
            for (int k = 0; k < qenv; k++) {
                string x;
                readNonEmptyLine(x);
                env.push_back(x);
            }
            ds.handleRegistrar(id, gioia, portador, qenv, env, cout);
        } else if (cmd == "PARADEIRO") {
            string gioia;
            readNonEmptyLine(gioia);
            ds.handleParadeiro(gioia, cout);
        } else if (cmd == "PROCURAR") {
            string nome;
            readNonEmptyLine(nome);
            ds.handleProcurar(nome, cout);
        } else if (cmd == "MENTIRA") {
            string sID;
            readNonEmptyLine(sID);
            int id = stoi(sID);
            ds.handleMentira(id, cout);
        } else {
            cout << "Comando invalido.\n";
        }

        if (i != N-1) cout << "\n";
    }

    return 0;
}
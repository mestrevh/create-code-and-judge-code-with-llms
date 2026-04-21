/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    string favorite;
    Node* next;
    Node(const string& n, const string& f) : name(n), favorite(f), next(nullptr) {}
};

class QueueLL {
    Node* head;
    Node* tail;
    int sz;
public:
    QueueLL() : head(nullptr), tail(nullptr), sz(0) {}
    ~QueueLL() { clear(); }
    QueueLL(const QueueLL&) = delete;
    QueueLL& operator=(const QueueLL&) = delete;

    bool empty() const { return sz == 0; }
    int size() const { return sz; }

    void push(const string& name, const string& fav) {
        Node* node = new Node(name, fav);
        if (!tail) head = tail = node;
        else { tail->next = node; tail = node; }
        sz++;
    }

    bool pop(string& outName) {
        if (!head) return false;
        Node* cur = head;
        outName = cur->name;
        head = head->next;
        if (!head) tail = nullptr;
        delete cur;
        sz--;
        return true;
    }

    void clear() {
        string dummy;
        while (pop(dummy)) {}
    }
};

static inline string trim(const string& s) {
    size_t b = 0;
    while (b < s.size() && isspace((unsigned char)s[b])) b++;
    size_t e = s.size();
    while (e > b && isspace((unsigned char)s[e-1])) e--;
    return s.substr(b, e-b);
}

static inline bool startsWith(const string& s, const string& pref) {
    return s.rfind(pref, 0) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    string ruFood, areaFood;

    while (getline(cin, line)) {
        line = trim(line);
        if (line.empty()) continue;
        if (startsWith(line, "RU:")) {
            ruFood = trim(line.substr(3));
            break;
        }
    }
    while (getline(cin, line)) {
        line = trim(line);
        if (line.empty()) continue;
        if (startsWith(line, "Area 2:")) {
            areaFood = trim(line.substr(string("Area 2:").size()));
            break;
        }
    }

    QueueLL qRU, qArea;

    vector<string> outputs;

    auto parseAdd = [&](const string& cmd) {
        string rest = trim(cmd);
        size_t posColon = rest.find(':');
        if (posColon == string::npos) {
            string name = trim(rest);
            string fav = "";
            bool toRU = false, toArea = false;

            if (!fav.empty() && ruFood == fav) toRU = true;
            if (!fav.empty() && areaFood == fav) toArea = true;

            if (!toRU && !toArea) {
                if (qRU.size() < qArea.size()) {
                    qRU.push(name, fav);
                    outputs.push_back(name + " foi para a fila do RU");
                } else if (qArea.size() < qRU.size()) {
                    qArea.push(name, fav);
                    outputs.push_back(name + " foi para a fila da Area 2");
                } else {
                    qArea.push(name, fav);
                    outputs.push_back(name + " foi para a fila da Area 2");
                }
                return;
            }

            if (toRU) {
                qRU.push(name, fav);
                outputs.push_back(name + " foi para a fila do RU");
            } else {
                qArea.push(name, fav);
                outputs.push_back(name + " foi para a fila da Area 2");
            }
            return;
        } else {
            string name = trim(rest.substr(0, posColon));
            string fav = trim(rest.substr(posColon + 1));

            bool toRU = false, toArea = false;
            if (fav == ruFood) toRU = true;
            if (fav == areaFood) toArea = true;

            if (toRU) {
                qRU.push(name, fav);
                outputs.push_back(name + " foi para a fila do RU");
                return;
            }
            if (toArea) {
                qArea.push(name, fav);
                outputs.push_back(name + " foi para a fila da Area 2");
                return;
            }

            if (qRU.size() < qArea.size()) {
                qRU.push(name, fav);
                outputs.push_back(name + " foi para a fila do RU");
            } else if (qArea.size() < qRU.size()) {
                qArea.push(name, fav);
                outputs.push_back(name + " foi para a fila da Area 2");
            } else {
                qArea.push(name, fav);
                outputs.push_back(name + " foi para a fila da Area 2");
            }
        }
    };

    while (getline(cin, line)) {
        line = trim(line);
        if (line.empty()) continue;

        if (startsWith(line, "SAIU:")) {
            string which = trim(line.substr(5));
            string name;
            if (which == "RU") {
                if (qRU.pop(name)) {
                    outputs.push_back(name + " almocou no RU e esta voltando pra aula");
                } else {
                    outputs.push_back("Nao ha mais ninguem para comer aqui");
                }
            } else if (which == "AREA2") {
                if (qArea.pop(name)) {
                    outputs.push_back(name + " almocou na Area 2 e esta voltando pra aula");
                } else {
                    outputs.push_back("Nao ha mais ninguem para comer aqui");
                }
            }
        } else {
            parseAdd(line);
        }
    }

    for (size_t i = 0; i < outputs.size(); i++) {
        cout << outputs[i];
        if (i + 1 < outputs.size()) cout << "\n";
    }
    return 0;
}
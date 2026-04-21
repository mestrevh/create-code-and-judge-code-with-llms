/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node(const string& n) : name(n), next(nullptr) {}
};

struct EraList {
    Node* head = nullptr;
    Node* tail = nullptr;

    bool contains(const string& s) const {
        for (Node* cur = head; cur; cur = cur->next) if (cur->name == s) return true;
        return false;
    }

    void push_back(const string& s) {
        Node* n = new Node(s);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }

    bool remove_by_name(const string& s) {
        Node* prev = nullptr;
        Node* cur = head;
        while (cur) {
            if (cur->name == s) {
                if (!prev) head = cur->next;
                else prev->next = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    vector<string> to_vector() const {
        vector<string> v;
        for (Node* cur = head; cur; cur = cur->next) v.push_back(cur->name);
        return v;
    }

    ~EraList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

string eraName(int idx) {
    if (idx == 0) return "Presente";
    if (idx == 1) return "Egito Antigo";
    if (idx == 2) return "Japao Feudal";
    return "Brasil Futurista";
}

int eraIndexForYear(long long year) {
    if (year == 2019) return 0;
    if (year >= -3100 && year <= -30) return 1;
    if (year >= 794 && year <= 1185) return 2;
    if (year >= 2235) return 3;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    EraList eras[4];
    unordered_map<string,int> pos;
    pos.reserve(1 << 15);

    string name;
    long long year;

    while (cin >> name >> year) {
        int targetEra = eraIndexForYear(year);
        if (targetEra == -1) {
            cout << "Cuidado pra nao ficar preso no reino quantico, " << name << ".\n";
            continue;
        }

        auto it = pos.find(name);
        int curEra;
        if (it == pos.end()) {
            curEra = 0;
            pos[name] = 0;
            eras[0].push_back(name);
        } else {
            curEra = it->second;
        }

        if (curEra == targetEra) {
            continue;
        }

        eras[curEra].remove_by_name(name);
        pos[name] = targetEra;
        eras[targetEra].push_back(name);

        cout << name << " foi de " << eraName(curEra) << " para " << eraName(targetEra) << ".\n";
    }

    bool any = false;
    for (int i = 1; i <= 3; i++) {
        vector<string> v = eras[i].to_vector();
        if (!v.empty()) {
            any = true;
            cout << eraName(i) << ":\n";
            for (size_t j = 0; j < v.size(); j++) {
                if (j) cout << ' ';
                cout << v[j];
            }
            cout << "\n";
        }
    }

    if (!any) {
        if (!pos.empty()) {
            cout << "\n";
        }
    } else {
        cout << "\n";
        vector<string> v0 = eras[0].to_vector();
        if (!v0.empty()) {
            cout << "Presente:\n";
            for (size_t j = 0; j < v0.size(); j++) {
                if (j) cout << ' ';
                cout << v0[j];
            }
            cout << "\n";
        }
    }

    if (any) return 0;

    vector<string> v0 = eras[0].to_vector();
    if (!v0.empty()) {
        cout << "\nPresente:\n";
        for (size_t j = 0; j < v0.size(); j++) {
            if (j) cout << ' ';
            cout << v0[j];
        }
        cout << "\n";
    } else {
        cout << "\n";
    }

    return 0;
}
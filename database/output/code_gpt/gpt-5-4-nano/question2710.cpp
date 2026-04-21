/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    long long endTime;
    double pct;
    Node* next;
    Node(string n, long long e, double p): name(std::move(n)), endTime(e), pct(p), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList(): head(nullptr) {}
    ~LinkedList() { clear(); }
    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = nullptr;
    }
    void pushBack(const string& name, long long endTime, double pct) {
        Node* n = new Node(name, endTime, pct);
        if (!head) {
            head = n;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
    void removeExpired(long long t) {
        while (head && head->endTime <= t) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        Node* cur = head;
        while (cur && cur->next) {
            if (cur->next->endTime <= t) {
                Node* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else cur = cur->next;
        }
    }
    bool best(long long t, string& outName) {
        removeExpired(t);
        if (!head) return false;
        Node* bestNode = head;
        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->pct > bestNode->pct) bestNode = cur;
        }
        outName = bestNode->name;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H;
    if (!(cin >> H)) return 0;

    vector<vector<tuple<string, long long, double>>> arrivals(H + 2);
    struct Person { long long start; string name; long long hours; double pct; };
    vector<Person> people;
    people.reserve(200000);

    while (true) {
        string name;
        long long start, hours;
        double pct;
        if (!(cin >> name >> start >> hours >> pct)) break;
        people.push_back({start, name, hours, pct});
    }

    for (auto &pr : people) {
        long long st = pr.start;
        if (st < 1) st = 1;
        long long endt = pr.start + pr.hours;
        if (st <= H) arrivals[st].push_back({pr.name, endt, pr.pct});
    }

    LinkedList lst;
    for (long long t = 1; t <= H; t++) {
        for (auto &it : arrivals[t]) {
            const string& nm = get<0>(it);
            long long endt = get<1>(it);
            double pct = get<2>(it);
            lst.pushBack(nm, endt, pct);
        }
        string ans;
        if (lst.best(t, ans)) {
            cout << "A melhor match para Frank é " << ans << "\n";
        } else {
            cout << "Não tem ninguém para Frank agora\n";
        }
    }
    return 0;
}
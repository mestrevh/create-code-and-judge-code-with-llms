/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    double score;
    Node* next;
    Node(string n, double s): name(std::move(n)), score(s), next(nullptr) {}
};

static string format4(double x) {
    ostringstream oss;
    oss.setf(std::ios::fixed); 
    oss << setprecision(4) << x;
    return oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double myNote;
    if (!(cin >> myNote)) return 0;

    const double target = 4.5;

    Node* head = nullptr;
    Node* tail = nullptr;
    vector<Node*> nodes; 
    string name;
    double score;

    while (cin >> name >> score) {
        Node* cur = new Node(name, score);
        if (!head) head = tail = cur;
        else { tail->next = cur; tail = cur; }
        nodes.push_back(cur);
    }

    int n = (int)nodes.size();

    double minDiff = 0.0;
    double maxDiff = 0.0;
    for (Node* cur : nodes) {
        double d = myNote - cur->score;
        if (d > minDiff) minDiff = d;
        if (d > maxDiff) maxDiff = d;
    }
    double limit = 0.0;
    if (n > 0) {
        double bestBelow = -1e100;
        for (Node* cur : nodes) {
            if (cur->score < myNote) bestBelow = max(bestBelow, cur->score);
        }
        if (bestBelow <= -1e90) {
            limit = -1e100;
        } else {
            limit = bestBelow;
        }
    } else {
        limit = -1e100;
    }

    auto it = head;
    while (it) {
        if (it->score < limit + 1e-12) {
            cout << it->name << " nao serve para aumentar minha nota.\n";
        }
        it = it->next;
    }

    double totalAdded = 0.0;

    auto applyPerson = [&](Node* person) {
        double diff = myNote - person->score;
        double add = 0.0;

        if (person->score >= myNote) add = 0.1 * (person->score - myNote);
        else {
            if (diff <= 0) add = 0.0;
            else add = 0.05 * (1.0 / (diff + 1.0));
        }

        if (add < 0) add = 0;
        myNote += add;
        totalAdded += add;

        cout << "Minha nota aumentou em " << format4(add) << " por causa de " << person->name << "!\n";
        cout << "Ja consegui aumentar " << format4(totalAdded) << " na minha nota\n";
        if (myNote + 1e-12 < target) {
            cout << "Atualmente estou com " << format4(myNote) << " e ainda falta " << format4(target - myNote) << " para conseguir a nota sonhada.\n";
        }
    };

    vector<string> notNeeded;
    it = head;

    vector<Node*> candidates;
    for (Node* cur : nodes) {
        if (!(cur->score < limit + 1e-12)) candidates.push_back(cur);
    }

    sort(candidates.begin(), candidates.end(), [&](Node* a, Node* b){
        if (a->score != b->score) return a->score > b->score;
        return a->name < b->name;
    });

    for (Node* p : candidates) {
        if (myNote + 1e-12 >= target) break;
        applyPerson(p);
    }

    if (myNote + 1e-12 >= target) {
        cout << "Consegui a nota sonhada, ja posso comprar a casa dos meus sonhos, nao preciso de mais ninguem.\n";
        for (Node* p : candidates) {
            if (p->score >= limit + 1e-12) {
                bool used = false;
                if (p->score >= limit + 1e-12) {
                    double tmp = myNote;
                }
            }
        }
        vector<Node*> usedSet;
        double curNote = 0.0;
        (void)curNote;

        int usedCount = 0;
        double checkNote = myNote - totalAdded;
        double running = checkNote;
        for (Node* p : candidates) {
            if (running + 1e-12 >= target) break;
            double diff = checkNote - p->score;
            double add = 0.0;
            if (p->score >= checkNote) add = 0.1 * (p->score - checkNote);
            else {
                if (diff <= 0) add = 0.0;
                else add = 0.05 * (1.0 / (diff + 1.0));
            }
            if (add < 0) add = 0;
            running += add;
            usedCount++;
        }
        for (int i = usedCount; i < (int)candidates.size(); i++) notNeeded.push_back(candidates[i]->name);

        if (!notNeeded.empty()) {
            cout << "Pessoas que nao preciso cativar:\n";
            for (auto &nm : notNeeded) cout << nm << "\n";
        }
    } else {
        cout << "Mesmo com tantos amigos nao consegui minha casa dos sonhos :(";
    }

    Node* cur = head;
    while (cur) {
        Node* nx = cur->next;
        delete cur;
        cur = nx;
    }
    return 0;
}